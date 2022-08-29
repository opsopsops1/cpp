// https://www.spoj.com/problems/PON/
#include <bits/stdc++.h>
using namespace std;
using ll = uint64_t;
using u128 = __uint128_t;   // <-----
using vi = vector<int>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

// Power
ll mod_pow(ll a, ll b, ll mod) {
  ll r = 1;
  a %= mod;
  while (b) {
    if (b&1) r = (u128)r*a%mod;
    b >>= 1;
    a = (u128)a*a%mod;
  }
  return r;
}

bool check_composite(ll n, ll a, ll d, ll s) {
  ll x = mod_pow(a, d, n);
  if (x == 1 || x == n-1) return false;
  for (int r = 1; r < s; ++r) {
    x = (u128)x*x%n;
    if (x == n-1) return false;
  }
  return true;
}

bool millar_Rabin(ll n) {
  if (n < 2) {
    return false;
  }
  ll d = n-1;
  ll s = 0;
  while (d%2 == 0) {
    ++s;
    d >>= 1;
  }
  for (int a: {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
    if (n == a) return true;
    if (check_composite(n, a, d, s)) {
      return false;
    }
  }
  return true;
}

void solve() {
  ll n;
  cin >> n;
  if (millar_Rabin(n)) cout << "YES" << endl;
  else cout << "NO" << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t = 1;
  cin >> t;
  rep(_,t) solve();
  return 0;
}
