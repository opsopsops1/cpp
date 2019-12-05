#include <bits/stdc++.h>
using namespace std;

bool dfs (const vector<vector<int>> G, vector<bool> &b, int u, int p) {
  b[u] = true;
  for (int v : G[u]) {
    if (v == p) continue;
    if (b[v]) return false;
    if (!dfs(G, b, v, u)) return false;
  }
  return true;
}

int main () {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m, u, v;
  cin >> n >> m;
  vector<vector<int> > g(n);
  for (int i = 0; i < m; ++i) {
    cin >> u >> v;
    g[u-1].push_back(v-1);
    g[v-1].push_back(u-1);
  }
  int t = 0;
  vector<bool> b(n, false);
  for (int i = 0; i < n; ++i) {
    if (b[i]) continue;
    if (dfs(g, b, i, i)) ++t;
  }
  cout << t << endl;
}

