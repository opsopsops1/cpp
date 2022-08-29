#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

bool normalize(P a, P b) {
  return (pow(a.first, 2) + pow(a.second, 2)) == (pow(b.first, 2) + pow(b.second, 2));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  vector<P> a(n), b(n);
  int gx=0, gy=0, hx=0, hy=0;
  auto f1 = [&] (vector<P> &p, int &x, int &y) {
    for (auto &pp : p) {
      cin >> pp.first >> pp.second;
      x += pp.first;
      y += pp.second;
    }
    return p;
  };
  f1(a, gx, gy);
  f1(b, hx, hy);
  if (n == 1) {
    cout << "Yes" << endl;
    return 0;
  }

  vector<P> na, nb;
  rep(i,n) {
    int x = a[i].first*n, y = a[i].second*n;
    x -= gx;  y-= gy;
    if (x == 0 && y == 0) continue;
    na.emplace_back(x, y);
  }
  rep(i,n) {
    int x = b[i].first*n, y = b[i].second*n;
    x -= hx;  y-= hy;
    if (x == 0 && y == 0) continue;
    nb.emplace_back(x, y);
  }
  if (na.size() != nb.size()) {
    cout << "No" << endl;
    return 0;
  }
  bool ok = false;
  int nn = na.size();
  auto f2 = [&] (vector<P> p, P c) {
    vector<P> t_p = p;
    for (auto &pp : t_p) {
      int x = pp.first, y = pp.second;
      pp.first = x*c.first - y*c.second;
      pp.second = x*c.second + y*c.first;
    }
    sort(t_p.begin(), t_p.end());
    // for (auto &pp : t_p) cout << pp.first << pp.second << endl;
    return t_p;
  };
  rep(i,nn) {
    // b[i] = a[0]
    if (!normalize(nb[i], na[0])) continue;
    vector<P> t_a, t_b;
    t_a = f2(na, nb[i]);
    t_b = f2(nb, na[0]);
    // cout << "============================\n";
    if (t_a == t_b) {
      ok = true;
      break;
    }
  }
  cout << (ok?"Yes":"No") << endl;
  return 0;
}