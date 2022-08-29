// https://atcoder.jp/contests/abc147/tasks/abc147_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i=0; i<(int)(n); ++i)

using P = pair<ll, ll>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  ll n, x, d;
  cin >> n >> x >> d;
  if (d == 0) {
    if (x == 0) cout << "1\n";
    else cout << n+1 << endl;
    return 0;
  }
  map<int, vector<P>> mp;
  rep(i, n+1) {
    ll s = i*x;
    ll l = (ll)i*(i-1)/2;
    s += l*d;
    ll rm = (s+(d<<30))%d;
    mp[rm].emplace_back((s-rm)/d, (n-i)*i);
  }
  ll ans = 0;
  for (auto p : mp) {
    auto a = p.second;
    vector<P> ev;
    for (auto pp : a) {
      ev.emplace_back(pp.first, 1);
      ev.emplace_back(pp.first+pp.second+1, -1);
    }
    sort(ev.begin(), ev.end());
    int cnt = 0;
    ll pre = -1e18;
    for (auto pp : ev) {
      ll len = pp.first - pre;
      if (cnt > 0) ans += len;
      cnt += pp.second;
      pre = pp.first;
    }
  }
  cout << ans << endl;
}
