// https://atcoder.jp/contests/tokiomarine2020/tasks/tokiomarine2020_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for(int i=0; i<(int)(n); ++i)
const int MX = 1e5+5;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, q;
  cin >> n;
  int limit = min(1023, n);
  vector<int> v(n+1), w(n+1);
  vector<vector<int>> dp(limit+1, vector<int>(MX));
  for (int i = 1; i <= n; ++i) cin >> v[i] >> w[i];
  for (int i = 1; i <= limit; ++i) {
    for (int j = 1e5; j >= w[i]; --j) {
      dp[i][j] = max(dp[i/2][j], dp[i/2][j-w[i]]+v[i]);
    }
    for (int j = w[i]-1; j >= 0; --j) {
      dp[i][j] = dp[i/2][j];
    }
  }

  cin >> q;
  rep(_, q) {
    int u, l;
    cin >> u >> l;
    vector<int> ids;
    while (u > limit) {
      ids.push_back(u);
      u >>= 1;
    }
    int ans = 0;
    int sz = ids.size();
    rep(t, (1<<sz)) {
      int sv = 0;
      int sw = 0;
      rep(i, sz) {
        if (t & (1<<i)) {
          sv += v[ids[i]];
          sw += w[ids[i]];
        }
      }
      if (sw <= l) {
        ans = max(ans, sv + dp[u][l-sw]);
      }
    }
    cout << ans << endl;
  }
}