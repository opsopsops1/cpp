#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for(int i=0; i<(int)(n); ++i)
const int M = 1e9 + 7;

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
struct combination {
  vector<int> fact, ifact;
  combination(int n):fact(n+1), ifact(n+1) {
    assert(n < M);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = mul(fact[i-1], i);
    ifact[n] = mod_pow(fact[n], M-2);
    for (int i = n; i >= 1; --i) ifact[i-1] = mul(ifact[i], i);
  }
  int operator()(int n, int k) {
    assert(k >= 0 && k <= n);
    return mul(fact[n], mul(ifact[k], ifact[n-k]));
  }
} C(2000005);

void solve() {
  int k;
  string s;
  cin >> k >> s;
  int n = s.size();

  ll ans = 0;
  for (int i = 0; i <= k; ++i) {
    ll now = mod_pow(25, i);
    now = (now * mod_pow(26, k-i)) % M;
    now = (now * C(n-1+i, n-1)) % M;
    ans = (ans + now) % M;
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solve();
}