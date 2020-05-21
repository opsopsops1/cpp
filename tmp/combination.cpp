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
}