// https://atcoder.jp/contests/arc005/tasks/arc005_3
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i=0; i<(int)(n); ++i)
#define rep2(i, a, b) for(int i=a; i<=(int)(b); ++i)
#define all(v) v.begin(),v.end()
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int h, w;
  cin >> h >> w;
  int sx, sy, gx, gy;
  vector<vector<int>> b(h+2, vector<int>(w+2));
  vector<vector<char>> c(h+2, vector<char>(w+2));
  rep2(i, 1, h) rep2(j, 1, w) {
    cin >> c[i][j];
    if (c[i][j] == 's') { sx = j; sy = i; }
    if (c[i][j] == 'g') { gx = j; gy = i; }
    b[i][j] = -1;
  }
  b[sy][sx] = 0;
  queue<pair<int, int>> q;
  q.emplace(sx, sy);
  int dx[] = {1, 0, -1, 0};
  int dy[] = {0, 1, 0, -1};
  while (!q.empty()) {
    int qx = q.front().first;
    int qy = q.front().second;
    q.pop();
    rep(i, 4) {
      int x = qx + dx[i];
      int y = qy + dy[i];
      if (b[y][x] == -1 || b[y][x] > b[qy][qx]) {
        if (c[y][x] == '#') b[y][x] = b[qy][qx] + 1;
        else b[y][x] = b[qy][qx];
        if (b[y][x] < 3) q.emplace(x, y);
      }
    }
  }
  if (b[gy][gx] == -1) cout << "NO\n";
  else cout << "YES\n";
}