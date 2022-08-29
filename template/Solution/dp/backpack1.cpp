#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for(int i=0; i<(int)(n); ++i)
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n = 4, W = 20;
  int w[] = {4, 5, 6, 7};
  int v[] = {7, 9, 10, 11};
  vector<int> dp(W+1);

  // backpack 1
  rep(i, n) {
    for (int j = W; j >= w[i]; --j) {
      dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
    }
  }
  cout << dp[W] << endl;

  // backpack 2
  dp.assign(W+1, 0);
  rep(i, n) {
    for (int j = w[i]; j <= W; ++j) {
      dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
    }
  }
  cout << dp[W] << endl;
}