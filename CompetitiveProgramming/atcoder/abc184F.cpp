// https://atcoder.jp/contests/abc184/tasks/abc184_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, t;
  cin >> n >> t;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  vector<ll> s1, s2;
  s1 = s2 = {0};
  rep(i,n) {
    for (int j = s1.size()-1; j >= 0; --j) {
     s1.push_back(s1[j] + a[i]);
    }
    swap(s1, s2);
  }
  sort(s1.begin(), s1.end());
  ll ans = 0;
  for (ll x : s2) {
    if (x > t) continue;
    int idx = upper_bound(s1.begin(), s1.end(), t-x) - s1.begin();
    ans = max(ans, s1[idx-1] + x);
  }
  cout << ans << endl;
  return 0;
}