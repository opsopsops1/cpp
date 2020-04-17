#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  for (auto &it : a) cin >> it;
  for (auto &it : b) cin >> it;
  for (int i = 0; i < n; ++i) c[i] = a[i] - b[i];
  
  sort(c.begin(), c.end());
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    if (c[i] <= 0) continue;
    int pos = upper_bound(c.begin(), c.end(), -c[i]) - c.begin();
    ans += i-pos;
  }
  cout << ans << endl;
}