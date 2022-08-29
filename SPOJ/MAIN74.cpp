// https://www.spoj.com/problems/MAIN74/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

const int M = 1000000007;

struct matrix {
  ll a, b, c, d;
  /* | a b |
     | c d | */
  matrix(ll a, ll b, ll c, ll d): a(a), b(b), c(c), d(d) {}
  matrix operator*(const matrix& mulMatrix)  {
    matrix res((a*mulMatrix.a%M+b*mulMatrix.c%M)%M, (a*mulMatrix.b%M+b*mulMatrix.d%M)%M, 
      (c*mulMatrix.a%M+mulMatrix.c*d%M)%M, (mulMatrix.b*c%M+d*mulMatrix.d%M)%M);
    return res;
  }
};

matrix pow_m(matrix a, ll b) {
  matrix r(1, 0, 0, 1);
  while (b) {
    if (b&1) {
      r = r * a;
    }
    b >>= 1;
    a = a*a;
  }
  return r;
}

void solve() {
  ll n;
  cin >> n;
  if (n == 0) {
    cout << 0 << endl;
    return;
  }
  if (n == 1) {
    cout << 2 << endl;
    return;
  }
  matrix f(1, 1, 1, 0);
  matrix pow_f = pow_m(f, n+2);
  cout << (pow_f.c+pow_f.d)%M << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t = 1;
  cin >> t;
  rep(_,t) solve();
  return 0;
}
