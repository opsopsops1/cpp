const int M = 998244353;
// Add
void add(ll& a, ll b) { a = (a+b)%M; }

// Multi
void mul(ll& a, ll b) { a = (a*b)%M; }

// Power
ll mod_pow(ll a, ll b) {
  ll r = 1;
  while (b) {
    if (b&1) mul(r, a);
    b >>= 1;
    mul(a, a);
  }
  return r;
}