#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i=a; i<n; ++i)

int main() {
  cin.tie(0), ios::sync_with_stdio(false);
  int n, m, T = 0;
  cin >> n >> m;
  vector<int> p(n+1), d(n+1), pin(n+1), pout(n+1);
  vector<vector<int>> G(n+1);
  
  rep(i, 0, n-1) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  
  function<void(int, int, int)> dfs = [&] (int ver, int par, int dep) {
    p[ver] = par;
    d[ver] = dep;
    pin[ver] = T++;
    for (auto to : G[ver]) {
      if (to == par) continue;
      dfs(to, ver, dep + 1);
    }
    pout[ver] = T++;
  };
  dfs(1, 0, 0);
  
  rep(i, 0, m) {
    int k;
    bool ok = true;
    cin >> k;
    vector<int> v(k);
    for (auto &it : v) cin >> it;
    int u = v[0];
    for (auto it : v) {
      if (d[u] < d[it]) u = it;
    }
    for (auto &it : v) {
      if (it == u) continue;
      if (p[it] != 0) it = p[it];
    }
    for (auto it : v) {
      ok &= (pin[it] <= pin[u] && pout[u] <= pout[it]);
    }
    cout << (ok?"YES\n":"NO\n");
  }
}