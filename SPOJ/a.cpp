#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

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
} prime(1000);

void solve() {
  int n;
  cin >> n;
  int ans = n;
  set<int> p;
  for (int x: prime.p) {
    while (n%x == 0) {
      n /= x;
      p.insert(x);
    }
  }
  if (n != 1) {
    p.insert(n);
  }
  for (int x: p) {
    ans /= x;
    ans *= (x-1);
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  time_t start = clock();
  int t = 1;
  cin >> t;
  rep(_,t) solve();
  time_t end = clock();
  // printf("%.f ms\n", difftime(end, start));
  return 0;
}
