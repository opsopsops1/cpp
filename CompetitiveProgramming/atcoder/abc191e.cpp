// https://atcoder.jp/contests/abc191/tasks/abc191_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)
const int INF = 1001001001;
struct Edge {
  int to, t;
  Edge(int to, int t): to(to), t(t) {}
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<Edge>> g(n);
  rep(i,m) {
    int a, b, c;
    cin >> a >> b >> c;
    --a, --b;
    g[a].emplace_back(b, c);
  }
  priority_queue<P, vector<P>, greater<P>> q;
  vector<int> dist;
  auto push = [&](int v, int x) {
    if (dist[v] <= x) return;
    dist[v] = x;
    q.emplace(x, v);
  };
  rep(s,n) {
    dist.assign(n, INF);
    for (auto e: g[s]) push(e.to, e.t);
    while (!q.empty()) {
      auto [d, v] = q.top(); q.pop();
      // if (dist[v] > d) {
      //   cout << "No\n";
      //   return 0;
      // }
      if (dist[v] < d) continue;
      for (auto e: g[v]) {
        push(e.to, d+e.t);
      }
    }
    if (dist[s] == INF) cout << "-1\n";
    else cout << dist[s] << endl;
  }
  return 0;
}