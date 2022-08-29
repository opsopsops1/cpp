// https://atcoder.jp/contests/abc191/tasks/abc191_c?lang=ja
// count right angle

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)
#define rrep(i,n) for(int i=1; i<=(int)(n); ++i)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int h, w;
  cin >> h >> w;
  vector<string> g(h);
  rep(i,h) cin >> g[i];
  int ans = 0;
  rep(i,h-1) rep(j,w-1) {
    int cnt = 0;
    rep(ii,2) rep(jj,2) {
      if (g[i+ii][j+jj] == '#') ++cnt;
    }
    if (cnt == 1 || cnt == 3) ++ans;
  }
  cout << ans << endl;
  return 0;
}