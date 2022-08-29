vector<int> prime;
vector<int> phi;

void euler_gen(int n) {
  bool is_compisite[n] = {};
  phi.assign(n);
  for (int i = 2; i < n; ++i) {
    if (!is_compisite[i]) {
      prime.push_back(i);
      phi[i] = i-1;
    for (int j = 0; j < prime.size(); i * prime[j] < n; ++j) {
      is_compisite[i * prime[j]] = true;
      if (i % prime[j] == 0) {
        phi[i * prime[j]] = phi[i] * prime[j];
        break;
      } else {
        phi[i * prime[j]] = phi[i] * phi[prime[j]];
      }
    }
  }
}