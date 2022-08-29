// https://atcoder.jp/contests/abc176/tasks/abc176_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for(int i=0; i<(int)(n); ++i)

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
const int INF = 1e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  int h, w;
  cin >> h >> w;
  int ci, cj;
  cin >> ci >> cj;
  int di, dj;
  cin >> di >> dj;
  --ci, --cj, --di, --dj;
  vector<string> s(h);
  rep(i,h) cin >> s[i];

  vector<vector<int>> dist(h, vector<int>(w, INF));
  deque<P> q;
  dist[ci][cj] = 0;
  q.emplace_back(ci, cj);
  while (!q.empty()) {
    int i = q.front().first;
    int j = q.front().second;
    int d = dist[i][j];
    q.pop_front();

    rep(mv,4) {
      int ni = i + dx[mv];
      int nj = j + dy[mv];
      if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
      if (s[ni][nj] == '#') continue;
      if (dist[ni][nj] <= d) continue;
      dist[ni][nj] = d;
      q.emplace_front(ni,nj);
    }

    for (int ei = -2; ei <= 2; ++ei) {
      for (int ej = -2; ej <= 2; ++ej) {
        int ni = i + ei;
        int nj = j + ej;
        if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
        if (s[ni][nj] == '#') continue;
        if (dist[ni][nj] <= d+1) continue;
        dist[ni][nj] = d+1;
        q.emplace_back(ni,nj);
      }
    }
  }
  int ans = dist[di][dj];
  if (ans == INF) ans = -1;
  cout << ans << endl;
}