// https://codeforces.com/contest/1341/problem/D
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i=0; i<(int)(n); ++i)
#define rep2(i, a, b) for(int i=a; i<=(int)(b); ++i)
#define all(v) v.begin(),v.end()

vector<string> digits = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, k;
  string s;
  cin >> n >> k;
  vector<vector<int>> d(n, vector<int>(10));

  rep(i, n) {
    cin >> s;
    rep(j, 10) {
      rep(l, 7) {
        char x = s[l];
        char y = digits[j][l];
        if (x == '1' && y == '0') {
          d[i][j] = -1;
          break;
        }
        if (x == '0' && y == '1') ++d[i][j];
      }
    }
  }
  vector<vector<int>> dp(n+1, vector<int>(k+1));
  dp[n][0] = 1;
  for (int i = n; i > 0; --i) {
    rep2(j, 0, k) {
      if (dp[i][j]) {
        rep(l, 10) {
          if (d[i-1][l] != -1 && j + d[i-1][l] <= k) dp[i-1][j+d[i-1][l]] = 1;
        }
      }
    }
  }
  if (dp[0][k] == 0) {
    cout << "-1\n";
    return 0;
  }
  rep(i, n) {
    int now;
    for (int l = 9; l >= 0; --l) {
      if (d[i][l] != -1 && k >= d[i][l] && dp[i+1][k-d[i][l]]) {
        now = l;
        k -= d[i][l];
        break;
      }
    }
    cout << now;
  }
  cout << "\n";
}