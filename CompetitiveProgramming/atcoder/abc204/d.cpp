#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, tot = 0;
  cin >> n;
  vector<int> a(n);
  rep(i,n) {
    cin >> a[i];
    tot += a[i];
  }
  vector<bool> dp(tot+1);
  dp[0] = true;
  rep(i,n) {
    for (int j = tot-a[i]; j >= 0; --j) {
      if (dp[j]) dp[j+a[i]] = true;
    }
  }
  for (int i = (tot+1) / 2;; ++i) {
    if (dp[i]) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}