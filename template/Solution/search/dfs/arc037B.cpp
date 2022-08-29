// https://atcoder.jp/contests/arc037/tasks/arc037_b
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i=0; i<(int)(n); ++i)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int t = 0;
  vector<bool> visit(n, false);
  function<bool(int, int)> dfs = [&] (int from, int p) {
    visit[from] = true;
    for (int to : g[from]) {
      if (to == p) continue;
      if (visit[to]) return false;
      if (!dfs(to, from)) return false;
    }
    return true;
  };
  rep(i, n) {
    if (visit[i]) continue;
    if (dfs(i, -1)) ++t;;
  }
  cout << t << "\n";
}