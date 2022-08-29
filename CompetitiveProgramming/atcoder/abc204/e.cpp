#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)
const ll MX = 1e18;

struct Edge {
  int to, c, d;
  Edge(int _to, int _c, int _d): to(_to), c(_c), d(_d) {};
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<Edge> G[n];
  rep(i,m) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    --a, --b;
    G[a].emplace_back(b, c, d);
    G[b].emplace_back(a, c, d);
  }
  vector<ll> dist(n, MX);
  dist[0] = 0;
  {
    queue<pair<ll, int>> q;
    q.emplace(0, 0);
    while (!q.empty()) {
      ll t = q.front().first;
      int f = q.front().second;
      q.pop();
      for (auto e : G[f]) {
        if (dist[e.to] < t) continue;
        ll add = MX;
        ll ss = sqrt(e.d);
        for (ll tt = max(t, ss-2); tt <= ss + 2; ++tt) {
          add = min(add, tt + e.d/(1+tt));
        }
        t = add + e.c;
        dist[e.to] = min(dist[e.to], t);
        q.emplace(t, e.to);
      }
    }
  }
  if (dist[n-1] == MX) dist[n-1] = -1;
  cout << dist[n-1] << endl;
  return 0;
}