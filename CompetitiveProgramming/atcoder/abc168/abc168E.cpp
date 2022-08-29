// https://atcoder.jp/contests/abc168/tasks/abc168_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for(int i=0; i<(int)(n); ++i)

ll gcd(ll a, ll b) { return (b?gcd(b, a%b):a); }

const int M = 1000000007;
ll mul(ll a, ll b) { return (a*b)%M; }
ll mod_pow(ll a, ll b) {
  ll r = 1;
  while (b) {
    if (b&1) r = mul(r, a);
    b >>= 1;
    a = mul(a, a);
  }
  return r;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, zero = 0;
  cin >> n;
  map<pair<ll, ll>, P> mp;
  rep(i, n) {
    ll x, y;
    cin >> x >> y;
    if (x == 0 && y == 0) {
      ++zero;
      continue;
    }
    ll g = gcd(x, y);
    x /= g;
    y /= g;
    if (y < 0) { x = -x, y = -y; }
    if (x == 0) y = 1;
    if (y == 0) x = 1;
    if (x > 0) mp[{x, y}].first++;
    else mp[{y, -x}].second++;
  }
  ll ans = 1;
  for (auto k : mp) {
    ll now1 = mod_pow(2, k.second.first);
    ll now2 = mod_pow(2, k.second.second);
    ans = mul(ans, (now1+now2-1)%M);
  }
  ans = (ans+M+zero-1)%M;
  cout << ans << endl;
}