// https://atcoder.jp/contests/abc164/tasks/abc164_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for(int i=0; i<(int)(n); ++i)

const int MAX_V = 50;
const int MAX_S = 50*MAX_V;
const ll INF = 1e18;

struct Edge {
  int to, a, b;
  Edge(int to, int a, int b):to(to), a(a), b(b) {}
};

struct Data {
  int v, s;
  ll x;
  Data(int v, int s, ll x):v(v), s(s), x(x) {}
  bool operator<(const Data& r) const {
    return x > r.x;
  }
};

vector<Edge> g[MAX_V];
ll dp[MAX_V][MAX_S+5];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, m, s;
  cin >> n >> m >> s;
  rep(i, m) {
    int u, v, a, b;
    cin >> u >> v >> a >> b;
    --u, --v;
    g[u].emplace_back(v, a, b);
    g[v].emplace_back(u, a, b);
  }
  vector<int> c(n), d(n);
  rep(i, n) cin >> c[i] >> d[i];
  rep(i, n) rep(j, MAX_S+5) dp[i][j] = INF;
  
  priority_queue<Data> q;
  auto push = [&] (int v, int s, ll x) {
    if (s < 0) return;
    if (dp[v][s] <= x) return;
    dp[v][s] = x;
    q.emplace(v, s, x);
  };
  push(0, min(s, MAX_S), 0);
  while (!q.empty()) {
    Data t = q.top(); q.pop();
    int v = t.v, s = t.s;
    ll x = t.x;
    push(v, min(s+c[v], MAX_S), x+d[v]);
    for (auto e : g[v]) {
      push(e.to, s-e.a, x+e.b);
    }
  }
  for (int i = 1; i < n; ++i) {
    ll ans = INF;
    rep(j, MAX_S+5) ans = min(ans, dp[i][j]);
    cout << ans << endl;
  }
}