#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  vector<pair<double, double>> p(n);
  rep(i,n) {
    int t;
    double l, r;
    cin >> t >> l >> r;
    if (t == 2) r -= 0.5;
    if (t == 3) l += 0.5;
    if (t == 4) {
      r -= 0.5;
      l += 0.5;
    }
    p[i] = make_pair(l, r);
  }
  int ans = 0;
  rep(i,n-1) for (int j=i+1; j < n; ++j) {
    if (max(p[i].first, p[j].first) <= min(p[i].second, p[j].second)) ans += 1;
  }
  cout << ans << endl;
  return 0;
}