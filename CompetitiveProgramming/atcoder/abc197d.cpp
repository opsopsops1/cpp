// https://atcoder.jp/contests/abc197/tasks/abc197_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

using C = complex<double>;
const double pi = acos(-1);
C in() {
  double x, y;
  cin >> x >> y;
  return C(x, y);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  C s = in(), t = in();
  C o = (s+t)/2.0;
  C ans = o + (s-o) * polar(1.0, 2*pi/n);
  printf("%.10f %.10f\n", ans.real(), ans.imag());
  return 0;
}