// https://atcoder.jp/contests/abc163/tasks/abc163_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i=0; i<(int)(n); ++i)

void chmax(ll& a, ll b) { if (a < b) a = b; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> p(n);
  rep(i, n) {
    int a;
    cin >> a;
    p[i] = make_pair(a, i);
  }
  sort(p.rbegin(), p.rend());
  
  vector<vector<ll>> dp(2005, vector<ll>(2005, 0ll));
  rep(i, n) {
    for (int j = 0; j+i < n; ++j) {
      int k = i+j;
      chmax(dp[i+1][j], dp[i][j] + 1ll*p[k].first*abs(p[k].second-i));
      chmax(dp[i][j+1], dp[i][j] + 1ll*p[k].first*abs(n-1-j-p[k].second));
    }
  }
  ll ans = 0;
  rep(i, n) chmax(ans, dp[i][n-i]);
  cout << ans << endl;
}