// https://atcoder.jp/contests/abc160/tasks/abc160_d
#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(false);
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> ans(n, 0);
  for (int i = 1; i <= n-1; ++i) {
    for (int j = i+1; j <= n; ++j) {
      int m = min(j-i, abs(x-i)+1+abs(y-j));
      ans[m]++;
    }
  }
  for (int i = 1; i < n; ++i) {
    cout << ans[i] << endl;
  }
}