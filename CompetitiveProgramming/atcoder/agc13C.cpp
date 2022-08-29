// https://atcoder.jp/contests/agc013/tasks/agc013_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  ll n, l, t;
  cin >> n >> l >> t;
  vector<ll> pos(n);
  int cur = 0;
  rep(i,n) {
    ll x, w;
    cin >> x >> w;
    if (w == 1) {
      x += t;
    } else {
      x -= t;
    }
    cur += x/l;
    if (x%l < 0) --cur; 
    pos[i] = (x%l+l)%l;
  }
  cur = (cur%n+n)%n;
  sort(pos.begin(), pos.end());
  rep(i,n) {
    cout << pos[(i+cur)%n] << endl;
  }
}