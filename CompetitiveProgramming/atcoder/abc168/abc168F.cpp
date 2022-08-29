#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for(int i=0; i<(int)(n); ++i)

struct Line {
  int a, b, c;
  Line(int a, int b, int c):a(a), b(b), c(c) {}
};

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  map<int, int> mx, my;
  vector<Line> lv, lh;
  mx[0]=0;
  my[0]=0;
  rep(i, n) {
    int a, b, c;
    cin >> a >> b >> c;
    mx[a] = 0;
    mx[b] = 0;
    my[c] = 0;
    lv.emplace_back(a, b, c);
  }
  rep(j, m) {
    int d, e, f;
    cin >> d >> e >> f;
    mx[d] = 0;
    my[e] = 0;
    my[f] = 0;
    lh.emplace_back(d, e, f);
  }
  vector<int> xv, yv;
  for (auto &p : mx) {
    p.second = xv.size();
    xv.push_back(p.first);
  }
  for (auto &p : my) {
    p.second = yv.size();
    yv.push_back(p.first);
  }
  int h = xv.size()*2;
  int w = yv.size()*2;

  vector<vector<int>> g(h, vector<int>(w));
  rep(i, n) {
    int a = mx[lv[i].a]*2;
    int b = mx[lv[i].b]*2;
    int c = my[lv[i].c]*2;
    for (int x = a; x <= b; ++x) g[x][c]=-1;
  }
  rep(j, m) {
    int d = mx[lh[j].a]*2;
    int e = my[lh[j].b]*2;
    int f = my[lh[j].c]*2;
    for (int y = e; y <= f; ++y) g[d][y]=-1;
  }
  queue<P> q;
  int sx = mx[0]*2;
  int sy = my[0]*2;
  g[sx][sy]=1;
  q.emplace(sx, sy);
  while (!q.empty()) {
    int x=q.front().first;
    int y=q.front().second;
    q.pop();
    rep(v, 4) {
      int nx = x+dx[v];
      int ny = y+dy[v];
      if (nx < 0 || nx >= h) continue;
      if (ny < 0 || ny >= w) continue;
      if (g[nx][ny] != 0) continue;
      g[nx][ny] = 1;
      q.emplace(nx, ny);
    }
  }
  ll ans = 0;
  rep(x, h) rep(y, w) {
    if (g[x][y] != 1) continue;
    if (x == 0 || x == h-1 || y == 0 || y == w-1) {
      cout << "INF\n";
      return 0;
    }
    if (x%2 == 0 || y%2 == 0) continue;
    ll ex = xv[x/2+1]-xv[x/2];
    ll ey = yv[y/2+1]-yv[y/2];
    ans += ex*ey;
  }
  cout << ans << endl;
  return 0;
}