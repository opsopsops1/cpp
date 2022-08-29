#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using vi = vector<int>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  sort(a.begin(),a.end());
  vector<ll> cum(n+1);
  rep(i,n) cum[i+1] = cum[i] + a[i];
  rep(i,q) {
    int x;
    cin >> x;
    if (x >= a[n-1]) {
      cout << (1ll)*x*n - cum[n] << endl;
    } else if (x <= a[0]) {
      cout << cum[n] - (1ll)*x*n << endl;
    } else {
      int idx = lower_bound(a.begin(),a.end(), x) - a.begin();
      cout << (cum[n]-cum[idx]-1ll*x*(n-idx)+1ll*x*(idx)-cum[idx]) << endl;
    }
  }
}
/*
2 4 6 8
3 -> 1
4 -> 1
5 -> 2
*/

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  time_t start = clock();
  int t = 1;
  // cin >> t;
  rep(_,t) solve();
  time_t end = clock();
  // printf("%.f ms\n", difftime(end, start));
  return 0;
}
