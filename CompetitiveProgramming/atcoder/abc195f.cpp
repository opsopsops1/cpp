// https://atcoder.jp/contests/abc195/tasks/abc195_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

vector<int> init() {
  vector<int> res;
  for (int i = 2; i < 73; ++i) {
    bool ok = true;
    for (int j = 2; j * j <= i; ++j) {
      if (i % j == 0) {
        ok = false;
        break;
      }
    }
    if (ok) res.push_back(i);
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  vector<int> prime = init();
  int n1 = prime.size();
  int n2 = (1 << n1);
  ll a, b;
  cin >> a >> b;
  vector<ll> dp(n2);
  dp[0] = 1;
  for (ll i = a; i <= b; ++i) {
    int s = 0;
    rep(j,n1) {
      if (i % prime[j] == 0) {
        s |= (1 << j);
      }
    }
    rep(j,n2) {
      if (j&s) continue;
      dp[j|s] += dp[j];
    }
  }
  ll ans = 0;
  rep(i,n2) {
    ans += dp[i];
  }
  cout << ans << endl;
  return 0;
}