// https://atcoder.jp/contests/tokiomarine2020/tasks/tokiomarine2020_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for(int i=0; i<(int)(n); ++i)
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, k, s, t;
  cin >> n >> k >> s >> t;
  vector<int> a;
  rep(i, n) {
    int x;
    cin >> x;
    if ((x&s) != s || (x|t) != t) continue;
    a.push_back(x);
  }
  n = a.size();
  k = min(n, k);
  if (n == 0) {
    cout << "0\n";
    return 0;
  }

  vector<vector<ll>> C(n+1, vector<ll>(n+1));
  rep(i, n+1) {
    C[i][0] = 1;
    for (int j = 1; j < i; ++j) C[i][j] = C[i-1][j] + C[i-1][j-1];
    C[i][i] = 1;
  }
  vector<ll> way(n+1);
  rep(i, n+1) {
    for (int j = 1; j <= min(i, k); ++j) way[i] += C[i][j];
  }
  
  ll ans = 0;
  int xo = s^t;
  vector<int> f(1<<18);

  // permutation
  for (int mask = xo;; mask = (mask-1)&xo) {
    ll sum = 0;
    for (int x : a) f[x&mask]++;

    for (int x : a) {
      sum += way[f[x&mask]];
      f[x&mask] = 0;
    }
    ans += (__builtin_popcount(mask)%2 ? -1 : 1)*sum;
    if (mask == 0) break;
  }
  cout << ans << endl;
}