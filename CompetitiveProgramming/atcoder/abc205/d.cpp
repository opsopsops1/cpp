#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, q;
  cin >> n >> q;
  vector<ll> a(n); 
  rep(i,n) cin >> a[i];
  vector<ll> c(n);
  rep(i,n) c[i] = a[i]-1-i;
  rep(i,q) {
    ll k;
    cin >> k;
    if (k > c.back()) {
      cout << a.back()+(k-c.back()) << endl;
      continue;
    }
    auto it = lower_bound(c.begin(), c.end(), k) - c.begin();
    cout << a[it]-1-(c[it]-k) << endl;
  }
  return 0;
}