#include <bits/stdc++.h>
using namespace std;
const int M = 998244353;
const int maxn = 2e5+5;

int main() {
  cin.tie(0), ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<long long> pow_ten(maxn);
  pow_ten[0] = 1;
  for (int i = 1; i < maxn; ++i) pow_ten[i] = pow_ten[i-1] * 10 % M;
  
  for (int i = 1; i < n; ++i) {
    cout << ((pow_ten[n-i-1]*2*9*10 + pow_ten[n-i-2]*(n-i-1)*9*9*10) % M) << " ";
  }
  cout << "10\n";
}