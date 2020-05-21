// https://atcoder.jp/contests/abc158/tasks/abc158_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i=0; i<(int)(n); ++i)
#define rep2(i, a, b) for(int i=a; i<=(int)(b); ++i)
#define all(v) v.begin(),v.end()
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, p;
  string s;
  cin >> n >> p;
  cin >> s;

  ll ans = 0;
  if (p == 2 || p == 5) {
    rep(i, n) {
      if ((s[i]-'0') % p == 0) ans += (i+1);
    }
    cout << ans << endl;
    return 0;
  }
  reverse(all(s));
  int ten = 1, a = 0;
  vector<int> cnt(p);
  rep(i, n) {
    ++cnt[a];
    a += ten * (s[i] - '0');
    a %= p;
    ten = ten * 10 % p;
    ans += cnt[a];
  }
  cout << ans << endl;
}