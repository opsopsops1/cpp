#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(false);
  int t;
  cin >> t;
  vector<int> v(100005);
  for (int i = 1; i < v.size(); ++i) v[i] = v[i-1] + i;
  
  while (t--) {
    int n, k;
    cin >> n >> k;
    auto it = lower_bound(v.begin(), v.end(), k);
    long long x = it - v.begin();
    for (int i = 0; i < n; ++i) {
      if ((n-1-i) == x || (n-1-i) == (k-x)) cout << 'b';
      else cout << 'a';
    }
    cout << endl;
  }
}