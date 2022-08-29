#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for(int i=0; i<(int)(n); ++i)
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  string s, t;
  cin >> s >> t;
  int a = s.size();
  int b = t.size();
  vector<vector<int>> dp(a+1, vector<int>(b+1, 0));
  for (int i = 0; i < a; ++i) {
    for (int j = 0; j < b; ++j) {
      if (s[i] == t[j]) {
        dp[i+1][j+1] = dp[i][j] + 1;
      } else {
        dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
      }
    }
  }
  cout << dp[a][b] << endl;
}