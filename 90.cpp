#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using vi = vector<int>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)
const int INF = 1001001001;
void solve() {
  int n;
  cin >> n;
  vector<int> g[n];
  rep(i,n-1) {
    int a, b;
    cin >> a >> b;
    --a;  --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<int> dist(n);
  queue<int> q;
  dist.assign(n, INF);
  dist[0] = 0;
  q.push(0);
  while (!q.empty()) {
    int u = q.front();  q.pop();
    for (auto v : g[u]) {
      if (dist[v] == INF) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
  int idx = -1;
  int mx = 0;
  rep(i,n) {
    if (dist[i] > mx) {
      idx = i;
      mx = dist[i];
    }
  }
  dist.assign(n, INF);
  dist[idx] = 0;
  q.push(idx);
  while (!q.empty()) {
    int u = q.front();  q.pop();
    for (auto v : g[u]) {
      if (dist[v] == INF) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
  int ans = 0;
  rep(i,n) {
    cout << dist[i] << endl;
    if (dist[i] > ans) ans = dist[i];
  }
  cout << ans + 1 << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t = 1;
  // cin >> t;
  rep(_,t) solve();
  return 0;
}