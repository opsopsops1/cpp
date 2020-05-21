// https://atcoder.jp/contests/abc155/tasks/abc155_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i=0; i<(int)(n); ++i)
#define all(a) a.begin(), a.end()

const ll INF = (ll)(1e18)+1;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n; ll k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  sort(all(a));
  ll l = -INF, r = INF;
  while (r - l > 1) {
    ll x = (r+l)/2;
    bool ok = [=] (void) -> bool {
      ll total = 0;
      rep(i, n) {
        if (a[i] < 0) {
          int l = -1, r = n;
          while (r - l > 1) {
            int id = (r+l) / 2;
            if (a[i] * a[id] < x) r = id;
            else l = id;
          }
          total += n-r;
        } else {
          int l = -1, r = n;
          while (r - l > 1) {
            int id = (r+l) / 2;
            if (a[i] * a[id] < x) l = id;
            else r = id;
          }
          total += r;
        }
        if (a[i] * a[i] < x) --total;
      }
      return total < 2*k;
    }();
    if (ok) l = x; else r = x;
  }
  cout << l;
}