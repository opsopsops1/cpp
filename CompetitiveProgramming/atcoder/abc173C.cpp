// https://atcoder.jp/contests/abc173/tasks/abc173_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  
  int h, w, k;
  cin >> h >> w >> k;
  vector<string> c(h);
  rep(i,h) cin >> c[i];

  int ans = 0;
  rep(si,1<<h) rep(sj,1<<w) {
    int cnt = 0;
    rep(i,h) {
      rep(j,w) {
        if (si>>i & 1) continue;
        if (sj>>j & 1) continue;
        if (c[i][j] == '#') ++cnt;
      }
    }
    if (cnt == k) ++ans;
  }
  cout << ans << endl;
}