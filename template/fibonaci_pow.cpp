
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

struct matrix {
  ll a, b, c, d;
  /* | a b |
     | c d | */
  matrix(ll a, ll b, ll c, ll d): a(a), b(b), c(c), d(d) {}
  matrix operator*(const matrix& mulMatrix)  {
    matrix res(a*mulMatrix.a+b*mulMatrix.c, a*mulMatrix.b+b*mulMatrix.d, 
      c*mulMatrix.a+mulMatrix.c*d, mulMatrix.b*c+d*mulMatrix.d);
    return res;
  }
};

matrix pow_m(matrix a, int b) {
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
  matrix f(1, 1, 1, 0);
  matrix pow_f = pow_m(f, n-1);
  cout << pow_f.c+pow_f.d << endl;  // F(n)
  // cout << pow_m(f,n).c << endl;   // F(n)
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  int t = 1;
  cin >> t;
  rep(_,t) solve();
  return 0;
}