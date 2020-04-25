#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for(int i=0; i<n; ++i)

inline ll count_c(int x) {
  return 1ll*x*(x-1)/2;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(false);
  int n;
  ll total = 0;
  cin >> n;
  vector<int> ball(n);
  vector<ll> c(n+1, 0), ans(n+1, 0);
  rep(i, n) {
    cin >> ball[i];
    ++c[ball[i]];
  }
  rep(i, n+1) {
    ans[i] = count_c(c[i]);
    total += ans[i];
  }
  rep(i, n) cout << (total - ans[ball[i]] + count_c(c[ball[i]]-1)) << endl;
}