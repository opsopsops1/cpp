// https://atcoder.jp/contests/abc175/tasks/abc175_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for(int i=0; i<(int)(n); ++i)
#define MX 1e15

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  ll x, k, d;
  cin >> x >> k >> d;
  x = abs(x);

  ll t = min(k, x/d);
  k -= t;
  x -= t*d;
  cout << (k&1?abs(x-d):x) << endl;
}