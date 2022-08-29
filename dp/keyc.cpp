// https://atcoder.jp/contests/keyence2021/tasks/keyence2021_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)
const int MAXH = 5005;
const int M = 998244353;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int h, w, k;
  cin >> h >> w >> k;
  vector<string> g(h, string(w, ' '));
  rep(i,k) {
    int a, b;
    char c;
    cin >> a >> b >> c;
    --a, --b;
    g[a][b] = c;
  }

  vector<ll> p3(MAXH, 1);
  for (int i = 1; i < MAXH; ++i) p3[i] = p3[i-1] * 3 % M;
  
  vector<vector<ll>> dn(h+1, vector<ll>(w+1)), rt(h+1, vector<ll>(w+1));
  vector<vector<ll>> dp(h+1, vector<ll>(w+1));
  rep(j,w) {
    for (int i = h-1; i >= 0; --i) dn[i][j] = dn[i+1][j]+(g[i][j] == ' ');
  }
  rep(i,h) {
    for (int j = w-1; j >= 0; --j) rt[i][j] = rt[i][j+1]+(g[i][j] == ' ');
  }
  dp[0][0] = 1;
  rep(i,h) rep(j,w) {
    if ((g[i][j] == 'X' || g[i][j] == 'R') && j+1 < w) {
      dp[i][j+1] += dp[i][j] * p3[dn[i+1][j]];
      dp[i][j+1] %= M;
    }
    if ((g[i][j] == 'X' || g[i][j] == 'D') && i+1 < h) {
      dp[i+1][j] += dp[i][j] * p3[rt[i][j+1]];
      dp[i+1][j] %= M;
    }
    if (g[i][j] == ' ') {
      dp[i][j+1] += 2 * dp[i][j] * p3[dn[i+1][j]];
      dp[i][j+1] %= M;
      dp[i+1][j] += 2 * dp[i][j] * p3[rt[i][j+1]];
      dp[i+1][j] %= M;
    }
  }
  if (g[h-1][w-1] == ' ') dp[h-1][w-1] = dp[h-1][w-1]*3%M;
  cout << dp[h-1][w-1] << endl;
  return 0;
}