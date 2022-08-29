// https://atcoder.jp/contests/arc116/tasks/arc116_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

const int M = 998244353;

ll add(ll a, ll b) { return (a+b)%M; }
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

struct Prime {
  vector<int> p;
  vector<int> sieve;
  Prime(int n=100): sieve(n+1) {
    for (int i = 1; i <= n; ++i) sieve[i] = i;
    for (int i = 2; i <= n; ++i) {
      if (sieve[i] == i) p.push_back(i);
      for (int pi = 0; pi < p.size(), i*p[pi] <= n; ++pi) {
        sieve[i*p[pi]] = p[pi];
        if (i % p[pi] == 0) break;
      }
    }
  }
  map<int, int> prime_divisor(int x) {
    map<int, int> res;
    while (x > 1) {
      res[sieve[x]]++;
      x /= sieve[x];
    }
    return res;
  }
};

struct Combination {
  vector<int> fact, ifact;
  Combination(int n):fact(n+1), ifact(n+1) {
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
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;

  Prime P(m);
  Combination C(n+m);
  int ans = 0;
  for (int i = 1; i <= m; ++i) {
    int now = 1;
    auto mp = P.prime_divisor(i);
    for (auto &[a, b]: mp) {
      now = mul(now, C(n-1+b, b));
    }
    ans = add(ans, now);
  }
  cout << ans << endl;
  return 0;
}