#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define rep(i, a, n) for(int i=a; i<n; ++i)
#define all(c) c.begin(), c.end()

int main() {
  cin.tie(0), ios::sync_with_stdio(false);
  int x, y, a, b, c;
  cin >> x >> y >> a >> b >> c;
  vector<int> p(a), q(b);
  for (int &t : p) cin >> t;
  for (int &t : q) cin >> t;
  sort(all(p));
  sort(all(q));
  
  vector<int> apple(c + x + y);
  rep(i, 0, c) cin >> apple[i];
  rep(i, a-x, a) apple[c + i - a + x] = p[i];
  rep(i, b-y, b) apple[c + x + i - b + y] = q[i];
  sort(all(apple));
  ll ans = 0;
  rep(i, c, apple.size()) ans += apple[i];
  cout << ans << endl;
}