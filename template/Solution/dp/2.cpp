#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for(int i=0; i<(int)(n); ++i)
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n = 4;
  int w[] = {2, 3, 4, 3};
  int v[] = {3, 4, 5, 5};
  int bigW = 20;
  vector<vector<int>> dp(n+1, vector<int>(bigW+1, 0));
  rep(i, n) for (int j = 0; j <= bigW; ++j) {
    for (int k = 0; k * w[i] <= j; ++k) {
      dp[i+1][j] = max(dp[i+1][j], dp[i][j-k*w[i]]+k*v[i]);
    }
  }
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= bigW; ++j) {
      cout << dp[i][j] << " \n"[j == bigW];
    }
  }
}