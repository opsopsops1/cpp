// https://atcoder.jp/contests/abc184/tasks/abc184_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)
const int INF = 1001001001;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int h, w;
  cin >> h >> w;
  vector<string> g(h);
  rep(i,h) cin >> g[i];
  
  queue<P> q;
  vector a(h, vector<int>(w, INF));
  rep(i,h) rep(j,w) {
    if (g[i][j] == 'S') {
      q.emplace(i, j);
      a[i][j] = 0;
    }
  }
  vector<vector<P>> warps(256);
  rep(i,h) rep(j,w) {
    warps[g[i][j]].emplace_back(i, j);
  }
  
  while (!q.empty()) {
    auto [x1, y1] = q.front();  q.pop();
    if (g[x1][y1] == 'G') {
      cout << a[x1][y1] << endl;
      return 0;
    }
    rep(d,4) {
      int x2 = x1+dx[d];
      int y2 = y1+dy[d];
      if (x2 < 0 || x2 >= h || y2 < 0 || y2 >= w || g[x2][y2] == '#') continue;
      if (a[x2][y2] != INF) continue;
      a[x2][y2] = a[x1][y1] + 1;
      q.emplace(x2, y2);
    }
    if (islower(g[x1][y1])) {
      for (auto&& [wx, wy] : warps[g[x1][y1]]) {
        // int wx = p.first, wy = p.second;
        if (a[wx][wy] != INF) continue;
        a[wx][wy] = a[x1][y1] + 1;
        q.emplace(wx, wy);
      }
      warps[g[x1][y1]].clear();
    }
  }
  puts("-1");
  return 0;
}