#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

void solve() {
  int n, m, a, b;
  cin >> n >> m;
  vector<vector<int>> g(n);
  rep(i, m) {
    cin >> a >> b;
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  int all_visit = (1 << n) - 1;
  function<int(int, int)> dfs = [&] (int u, int visit) {
    int res = 0;
    for (int v : g[u]) {
      int nvisit = visit | (1 << v);
      if (nvisit == visit) continue;
      if (nvisit == all_visit) {
        res += 1;
      } else {
        res += dfs(v, nvisit);
      }
    }
    return res;
  };
  cout << dfs(0, 1) << endl;
}

int main () {
  cin.tie(0), ios::sync_with_stdio(false);
  solve();
}
