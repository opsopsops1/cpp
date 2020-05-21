// https://atcoder.jp/contests/abc159/tasks/abc159_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define rep(i, n) for(int i=0; i<(int)(n); ++i)

const int M = 998244353;
void add(ll &x, ll y) { x = (x+y)%M; }

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  
  int n, s;
  cin >> n >> s;
  vector<ll> a(n);
  for (ll &x : a) cin >> x;
  vector<ll> q(s+1);
  ll ans = 0;
  rep(i, n) {
    add(q[0], 1);
    //-----
    for (int j = s; j >= 0; --j) if (j + a[i] <= s) add(q[j + a[i]], q[j]);
    //-----
    add(ans, q[s]);
  }
  cout << ans << endl;
}