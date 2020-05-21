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