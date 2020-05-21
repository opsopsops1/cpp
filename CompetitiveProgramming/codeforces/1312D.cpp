// https://codeforces.com/contest/1312/problem/D
#include <bits/stdc++.h>
using namespace std;
const int M = 998244353;

int mul(int m1, int m2) {
  return (1ll * m1 * m2 % M);
}

int mod_pow(int x, int y) {
  int z = 1;
  while (y) {
    if (y & 1) z = mul(z, x);
    x = mul(x, x);
    y >>= 1;
  }
  return z;
}

int divide(int m1, int m2) {
  return mul(m1, mod_pow(m2, M-2));
}

int main() {
  cin.tie(0), ios::sync_with_stdio(false);
  int n, m, ans = 0;
  cin >> n >> m;
  vector<int> fact(200005);
  fact[0] = 1;
  for (int i = 1; i < 200005; ++i) fact[i] = mul(fact[i-1], i);
  if (n > 2) ans = mul(divide(fact[m], mul(fact[n-1], fact[m-n+1])), mul(n-2, mod_pow(2, n-3)));
  cout << ans << endl;
}