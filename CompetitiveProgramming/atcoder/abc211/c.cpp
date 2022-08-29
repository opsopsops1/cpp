#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

const int MX = 100005;
const string title = "chokudai";
const int mod = 1e9+7;
ll dp[10][MX];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  string s;
  cin >> s;
  int n = s.length();
  if (s[0] == title[0]) dp[0][0] = 1;
  for (int i=1; i < n; ++i) {
    dp[0][i] = dp[0][i-1];
    if (s[i] == 'c') dp[0][i] += 1;
  }
  for (int i = 1; i < 8; ++i) {
    for (int j = 1; j < n; ++j) {
      if (s[j] == title[i]) {
        dp[i][j] = (dp[i][j-1] + dp[i-1][j-1])%mod;
      } else {
        dp[i][j] = dp[i][j-1];
      }
    }
  }
  cout << dp[7][n-1] << endl;
  return 0;
}