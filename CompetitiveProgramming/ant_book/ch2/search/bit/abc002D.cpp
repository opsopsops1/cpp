// https://atcoder.jp/contests/abc002/tasks/abc002_4
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i=0; i<(int)(n); ++i)
#define rep2(i, a, b) for(int i=a; i<=(int)(b); ++i)
#define all(v) v.begin(),v.end()

bool p[15][15];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    p[u-1][v-1] = true;
  }
  int ans = 1;
  rep(i, (1<<n)) {
    bitset<12> b(i);
    bool ok = true;
    rep(j, n) {
      rep2(k, j+1, n-1) {
        if (b.test(j) && b.test(k)) ok &= p[j][k];
      }
    }
    if (ok) ans = max<int>(ans, b.count());
  }
  cout << ans << "\n";
}