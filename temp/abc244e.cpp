// https://atcoder.jp/contests/abc244/tasks/abc244_e
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using vi = vector<int>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

const int M = 998244353;
ll dp[2005][2005][2];

void solve() {
  int n, m, k, s, t, x;
  cin >> n >> m >> k >> s >> t >> x;
  --s, --t, --x;
  vector<vector<int>> g(n);
  rep(i,m) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dp[0][s][0] = 1;
  rep(ki, k+1) rep(u, n) rep(i,2) {
    for (auto v: g[u]) {
      int ni = (v == x?i^1:i);
      dp[ki+1][v][ni] += dp[ki][u][i];
      dp[ki+1][v][ni] %= M;
    }
  }
  cout << dp[k][t][0] << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t = 1;
  // cin >> t;
  rep(_,t) solve();
  return 0;
}