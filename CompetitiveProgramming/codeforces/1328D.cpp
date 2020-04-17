#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define rep(i, a, n) for(int i=a; i<n; ++i)
#define all(c) c.begin(), c.end()
#define INF 1e18+1

void solve() {
  int n;
  cin >> n;
  vector<int> t(n);
  rep(i, 0, n) cin >> t[i];
  if (count(all(t), t.back()) == n) {
    cout << "1\n";
    rep(i, 0, n) cout << "1" << " \n"[i == n-1];
    return;
  }
  if (n%2 == 0) {
    cout << "2\n";
    rep(i, 0, n) cout << i%2 + 1 << " \n"[i == n-1];
    return;
  }
  rep(i, 0, n) {
    if (t[i] == t[(i + 1) % n]) {
      vector<int> ans(n);
      for (int j = i+1, v = 0; j < n; ++j, v ^= 1) ans[j] = v+1;
      for (int j = i, v = 0; j >= 0; --j, v ^= 1) ans[j] = v+1;
      cout << "2\n";
      rep(j, 0, n) cout << ans[j] << " \n"[j == n-1];
      return;
    }
  }
  cout << "3\n";
  rep(i, 0, n-1) cout << i%2 + 1 << " ";
  cout << "3\n";
}

int main() {
  cin.tie(0), ios::sync_with_stdio(false);
  int q;
  cin >> q;
  while (q--) solve();
}