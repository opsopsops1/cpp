#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;
void solve () {
  int n, k;
  cin >> n >> k;
  unordered_set<string> cnt;
  vector<string> s(n);
  rep(i, n) cin >> s[i];
  function<void(string, int, int)> dfs = [&] (string st, int kk, int u) {
    if (kk == k) {
      cnt.insert(st);
    } else {
      rep(i, n) {
        if ((u & (1 << i)) != 0) continue;
        dfs(st + s[i], kk + 1, u | (1 << i));
      }
    }
  };
  dfs("", 0, 0);
  cout << cnt.size() << endl;
}
int main () {
  cin.tie(0), ios::sync_with_stdio(false);
  solve();
}
