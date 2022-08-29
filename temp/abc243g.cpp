// https://atcoder.jp/contests/abc243/tasks/abc243_g
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using vi = vector<int>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

const int MX = 55000;
ll dp[MX+5];

ll sqrt_(ll x) {
  ll l = 0, r = ll(3e9)+1;
  while (l + 1 < r) {
    ll m = (l+r) / 2;
    if (m*m <= x) l = m; else r = m; 
  }
  return l;
}

void solve() {
  ll x;
  cin >> x;
  ll r = sqrt_(x);
  ll ans = 0;
  for (ll i = 1; i < MX; ++i) {
    ll l = i * i;
    if (l <= r) ans += (r-l+1) * dp[i];
    else break;
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  dp[1] = 1;
  for (int i = 1; i < MX, i*i < MX; ++i) {
    for (int j = i*i; j < MX; ++j) {
      if (j != i) dp[j] += dp[i];
    }
  }
  int t = 1;
  cin >> t;
  rep(_,t) solve();
  return 0;
}