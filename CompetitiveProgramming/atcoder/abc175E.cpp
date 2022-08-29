// https://atcoder.jp/contests/abc175/tasks/abc175_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for(int i=0; i<(int)(n); ++i)
const int D = 3005;

int d[D][D];
ll dp[D][D][4];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  
  int r, c, k;
  cin >> r >> c >> k;

  rep(i,k) {
    int a, b, v;
    cin >> a >> b >> v;
    d[a-1][b-1] = v;
  }
  rep(i,r) rep(j,c) {
    ;
    for (int t = 2; t >= 0; --t) {
      dp[i][j][t+1] = max<ll>(dp[i][j][t+1], dp[i][j][t] + d[i][j]);
    }
    for (int t = 0; t < 4; ++t) {
      dp[i+1][j][0] = max<ll>(dp[i+1][j][0], dp[i][j][t]);
      dp[i][j+1][t] = max<ll>(dp[i][j+1][t], dp[i][j][t]); 
    }
  }
  ll ans = 0;
  rep(t,4) ans = max<ll>(ans, dp[r-1][c-1][t]);
  cout << ans << endl;
}