#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using u128 = __uint128_t;
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

u128 str_to_u128(string s) {
  u128 res = 0;
  for (auto x: s) {
    res = res*10 + (x-'0');
  }
  return res;
}

u128 mult(u128 a, u128 b, u128 mod) {
  // return a * b % mod
  u128 res = 0;
  while (b) {
    if (b&1) {
      res = (res+a) % mod;
    }
    a = a*2%mod;
    b >>= 1;
  }
  return res;
}

u128 f(u128 a, u128 b, u128 mod) {
  // return (a*a + b) % mod
  return (mult(a, a, mod) + b) % mod;
}

u128 my_gcd(u128 a, u128 b) {
  return (b?my_gcd(b, a%b):a);
}

u128 my_abs(u128 x) {
  return (x>0?x:-x);
}

u128 brent(u128 n) {
  u128 x = (u128)rand()%(n-1)+1;
  u128 c = (u128)rand()%(n-1)+1;
  u128 m = (u128)rand()%(n-1)+1;
  u128 g = 1;
  u128 q = 1;
  u128 xs, y;

  int l = 1;
  while (g == 1) {
    y = x;
    for (int i = 1; i < l; ++i) {
      x = f(x, c, n);
    }
    int k = 0;
    while (k < l && g == 1) {
      xs = x;
      for (int i = 0; i < m && i < l-k; ++i) {
        x = f(x, c, n);
        q = mult(q, my_abs(y-x), n);
      }
      g = my_gcd(q,n);
      k += m;
    }
    l *= 2;
  }
  if (g == n) {
    do {
      xs = f(xs, c, n);
      g = my_gcd(my_abs(xs-y), n);
    } while (g <= 1);
  }
  return g;
}

string u128_to_str(u128 n) {
  string res;
  while (n) {
    res.push_back('0'+n%10);
    n /= 10;
  }
  reverse(res.begin(), res.end());
  return res;
}
void factor(u128 n, map<u128, int> &fa) {
  if (n == 1) return;
  if (n < 1e18 && millar_Rabin(n)) {
    fa[n] += 1;
    return;
  }
  u128 g = brent(n);
  factor(g, fa);
  factor(n/g, fa);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  string s;
  for(;;) {
    cin >> s;
    if (s == "0") break;
    u128 n = str_to_u128(s);
    map<u128, int> fact;
    factor(n, fact);
    for (auto p: fact) {
      cout << u128_to_str(p.first) << "^" << p.second << " ";
    }
    cout << endl;
  }
  return 0;
}
