#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using i128 = __int128_t;
using vi = vector<int>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

i128 str_to_i128(string s) {
  i128 res = 0;
  for (auto x: s) {
    res = res*10 + (x-'0');
  }
  return res;
}

i128 mult(i128 a, i128 b, i128 mod) {
  // return a * b % mod
  i128 res = 0;
  while (b) {
    if (b&1) {
      res = (res+a) % mod;
    }
    a = a*2%mod;
    b >>= 1;
  }
  return res;
}

i128 f(i128 a, i128 b, i128 mod) {
  return (mult(a, a, mod) + b) % mod;
}

i128 my_gcd(i128 a, i128 b) {
  return (b?my_gcd(b, a%b):a);
}

i128 my_abs(i128 x) {
  return (x>0?x:-x);
}

string i128_to_str(i128 n) {
  string res;
  while (n) {
    res.push_back('0'+n%10);
    n /= 10;
  }
  if (res.size() == 0) return "0";
  reverse(res.begin(), res.end());
  return res;
}

i128 rho(i128 n, i128 x0=3, i128 y0=1) {
  while (1) {
    i128 x = x0++;
    i128 c = y0;
    i128 y = x;

    while (1) {
      x = f(x, c, n);
      y = f(y, c, n);
      y = f(y, c, n);
      // if (x == y) break;

      i128 g = my_gcd(n, my_abs(x-y));
      if (g != 1) return g;
      if (x == y) break;
    }
  }
}



bool solve() {
  string s;
  cin >> s;
  if (s == "0") return false;
  i128 n = str_to_i128(s);
  map<i128, int> fact;
  for (auto x: {2, 3, 5}) {
    while (n%x == 0) {
      fact[x] += 1;
      n /= x;
    }
  }
  while (n != 1) {
    i128 g = rho(n);
    // while (g != rho(g)) g = rho(g, 3, 1);
    while (n%g == 0) {
      fact[g] += 1;
      n /= g;
    }
  }
  for (auto p: fact) {
    cout << i128_to_str(p.first) << "^" << p.second << " ";
  }
  cout << endl;
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t = 15;
  // cin >> t;
  rep(_,t) {
    if (!solve()) return 0;
  }
  return 0;
}
