// https://atcoder.jp/contests/abc231/tasks/abc231_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> rows(n);
  rep(i,n) cin >> rows[i];
  sort(rows.begin(), rows.end());
  rep(i,q) {
    int h;
    cin >> h;
    int l = -1, r = n;
    while (r - l > 1) {
      ll m = (0ll + l + r) / 2;
      if (rows[m] >= h) r = m;
      else l = m;
    }
    cout << n-r << endl;
  }
  return 0;
}