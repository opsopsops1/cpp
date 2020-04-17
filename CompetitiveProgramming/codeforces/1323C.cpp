#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(false);
  int n, cur=0;
  string s;
  cin >> n >> s;
  
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(') v[i] = cur++ + 1;
    else v[i] = cur-- - 1;
  }
  if (n%2 || v.back() != 0) cout << "-1\n";
  else {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (v[i] < 0 || (v[i] == 0 && v[i-1] < 0)) ++ans;
    }
    cout << ans << endl;
  }
}