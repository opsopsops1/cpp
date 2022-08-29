// https://atcoder.jp/contests/abc147/tasks/abc147_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for(int i=0; i<(int)(n); ++i)

const int D = 80*160 + 10;
using bs = bitset<2*D>;
bs dp[85][85];
int a[85][85];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int h, w;
  cin >> h >> w;
  rep(i, h) rep(j, w) cin >> a[i][j];
  rep(i, h) rep(j, w) {
    int x;
    cin >> x;
    a[i][j] = abs(x-a[i][j]);
  }
  dp[0][0][D-a[0][0]] = 1;
  dp[0][0][D+a[0][0]] = 1;
  rep(i, h) rep(j, w) {
    if (i) {
      dp[i][j] |= dp[i-1][j]<<a[i][j];
      dp[i][j] |= dp[i-1][j]>>a[i][j];
    }
    if (j) {
      dp[i][j] |= dp[i][j-1]<<a[i][j];
      dp[i][j] |= dp[i][j-1]>>a[i][j];
    }
  }
  rep(i, D) {
    if (dp[h-1][w-1][D-i] || dp[h-1][w-1][D+i]) {
      cout << i << endl;
      return 0;
    }
  }
}