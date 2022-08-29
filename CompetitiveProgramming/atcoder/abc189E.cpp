#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vl = vector<ll>;
using vp = vector<P>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)
#define rrep(i,n) for(int i=1; i<=(int)(n); ++i)
#define all(a) a.begin(), a.end()
#define yn puts("Yes"); else puts("No")

vector<ll> mul(vector<ll> a, int a11, int a12, int a21, int a22, int p1=0, int p2=0) {
  vector<ll> res(6);
  res[0] = a[0]*a11 + a[2]*a12;
  res[1] = a[1]*a11 + a[3]*a12;
  res[2] = a[0]*a21 + a[2]*a22;
  res[3] = a[1]*a21 + a[3]*a22;
  res[4] = a[4]*a11 + a[5]*a12 + p1;
  res[5] = a[4]*a21 + a[5]*a22 + p2;
  return res;
}
pair<ll, ll> print(vector<ll> a, pair<int, int> b) {
  pair<ll, ll> res;
  res.first = a[0]*b.first + a[1]*b.second + a[4];
  res.second = a[2]*b.first + a[3]*b.second + a[5];
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, m, q;
  cin >> n;
  vector<pair<int, int>> vp(n);
  for (auto &[x, y] : vp) {
    cin >> x >> y;
  }
  cin >> m;
  vector<vector<ll>> vv(m+1, vector<ll>(6));
  vv[0][0] = vv[0][3] = 1;
  for (int i = 0; i < m; ++i) {
    int op, p;
    cin >> op;
    if (op == 1) {
      vv[i+1] = mul(vv[i], 0, 1, -1, 0);
    } else if (op == 2) {
      vv[i+1] = mul(vv[i], 0, -1, 1, 0);
    } else {
      cin >> p;
      if (op == 3) {
        vv[i+1] = mul(vv[i], -1, 0, 0, 1, 2*p, 0);
      } else {
        vv[i+1] = mul(vv[i], 1, 0, 0, -1, 0, 2*p);
      }
    }
  }
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int a, b;
    cin >> a >> b;
    --b;
    auto pp = print(vv[a], vp[b]);
    printf("%lld %lld\n", pp.first, pp.second);
  }
  return 0;
}