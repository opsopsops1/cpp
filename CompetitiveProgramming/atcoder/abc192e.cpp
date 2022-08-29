// Dijkstra's algorithm
// https://atcoder.jp/contests/abc192/tasks/abc192_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,int>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)
const ll INF = 1e18;

struct Edge {
  int to, t, k;
  Edge(int to, int t, int k): to(to), t(t), k(k) {}
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  --x, --y;
  vector<vector<Edge>> g(n);
  rep(i,m) {
    int a, b, t, k;
    cin >> a >> b >> t >> k;
    --a, --b;
    g[a].emplace_back(b, t, k);
    g[b].emplace_back(a, t, k);
  }
  vector<ll> dist(n, INF);
  priority_queue<P, vector<P>, greater<P>> q;
  auto push = [&](int v, ll x) {
    if (dist[v] <= x) return;
    dist[v] = x;
    q.emplace(x, v);
  };
  push(x, 0);
  while (!q.empty()) {
    auto [x, v] = q.top(); q.pop();
    if (dist[v] != x) {
      continue;
    }
    for (auto e : g[v]) {
      ll nx = (x+e.k-1) / e.k * e.k + e.t;
      push(e.to, nx);
    }
  }
  if (dist[y] == INF) cout << "-1\n";
  else cout << dist[y] << endl;
  return 0;
}