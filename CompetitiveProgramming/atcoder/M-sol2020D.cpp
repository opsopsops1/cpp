// https://atcoder.jp/contests/m-solutions2020/tasks/m_solutions2020_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for(int i=0; i<(int)(n); ++i)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n; cin >> n;
  ll a[85], dp[85];
  for (int i = 1; i <= n; ++i) cin >> a[i];
  dp[1] = 1000;
  for (int i = 2; i <= n; ++i) {
    dp[i] = dp[i-1];
    for (int j = 1; j <= i-1; ++j) {
      ll b = dp[j] / a[j];
      ll v = dp[j] + (a[i]-a[j]) * b;
      dp[i] = max(dp[i], v);
    }
  }
  cout << dp[n] << endl;
}