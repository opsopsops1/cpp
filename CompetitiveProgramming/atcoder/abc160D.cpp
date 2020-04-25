#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define rep(i, a, n) for(int i=a; i<n; ++i)
#define all(c) c.begin(), c.end()
#define INF 1e18+1

int main() {
  cin.tie(0), ios::sync_with_stdio(false);
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> ans(n, 0);
  for (int i = 1; i <= n-1; ++i) {
    for (int j = i+1; j <= n; ++j) {
      int m = min(j-i, min(abs(x-i)+1+abs(y-j), abs(y-i)+1+abs(x-j)));
      ans[m]++;
    }
  }
  for (int i = 1; i < n; ++i) {
    cout << ans[i] << endl;
  }
}