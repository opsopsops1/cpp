#include <bits/stdc++.h>
using namespace std;

int main () {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int h, w;
  int sx, sy, gx, gy;
  int dx[] = {0, 1, 0, -1};
  int dy[] = {1, 0, -1, 0};
  cin >> h >> w;
  char c[h+2][w+2];
  vector<vector<int>> v(h+2, vector<int>(w+2, 0));
  // -1 means not arriving, x means destroy x fence
  for (int i = 1; i <= h; ++i) {
    for (int j = 1; j <= w; ++j) {
      cin >> c[i][j];
      if (c[i][j] == 's') { sx = j; sy = i; }
      if (c[i][j] == 'g') { gx = j; gy = i; }
      v[i][j] = -1;
    }
  }
  v[sy][sx] = 0;
  queue<pair<int, int>> q;
  q.emplace(sx, sy);
  while (!q.empty()) {
    int qx = q.front().first;
    int qy = q.front().second;
    q.pop();
    for (int i = 0; i < 4; ++i) {
      int x = qx + dx[i];
      int y = qy + dy[i];
      if (v[y][x] == -1 || v[y][x] > v[qy][qx]) {
        if (c[y][x] == '#') v[y][x] = v[qy][qx] + 1;
        else v[y][x] = v[qy][qx];
        if (v[y][x] < 3) q.emplace(x, y);
      }
    }
  }
  if (v[gy][gx] == -1) cout << "NO\n";
  else cout << "YES\n";
}

