// https://atcoder.jp/contests/abc179/tasks/abc179_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  ll n, x, m, ans = 0;
  cin >> n >> x >> m;
  vector<ll> s(m, -1);
  vector<ll> a;
  int cnt = 0;
  ll tot = 0;
  while (s[x] == -1) {
    a.push_back(x);
    s[x] = cnt;
    tot += x;
    ++cnt;
    x = (x*x)%m;
  }
  
  if (n <= cnt) {
    rep(i,n) ans += a[i];
  } else {
    int re = cnt - s[x];
    ll tot2 = 0;
    for (int i = s[x]; i < cnt; ++i) tot2 += a[i];

    ans += tot;
    n -= cnt;
    ans += (n/re)*tot2;
    n %= re;
    rep(i,n) ans += a[s[x]+i];
  }
  cout << ans << endl;
}