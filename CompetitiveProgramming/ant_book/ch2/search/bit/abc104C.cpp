// https://atcoder.jp/contests/abc104/tasks/abc104_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i=0; i<(int)(n); ++i)
#define rep2(i, a, b) for(int i=a; i<=(int)(b); ++i)
#define all(v) v.begin(),v.end()
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int d, g;
  cin >> d >> g;
  int p[15], c[15];
  rep(i, d) cin >> p[i] >> c[i];
  int ans = 1e6;
  rep(i, (1<<d)) {
    bitset<10> b(i);
    int total=0, num=0, r=-1;
    rep(j, d) {
      if (b.test(j)) {
        total += p[j]*100*(j+1) + c[j];
        num += p[j];
      } else {
        r = j;
      }
    }
    if (total < g) {
      int need = (g-total+100*(r+1)-1) / (100*(r+1));
      if (need >= p[r]) continue;
      num += need;
    }
    ans = min(ans, num);
  }
  cout << ans << "\n";
}