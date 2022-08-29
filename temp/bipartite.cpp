// https://atcoder.jp/contests/code-festival-2017-qualb/tasks/code_festival_2017_qualb_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for(int i=0; i<(int)(n); ++i)
const int MAX_N = 1e5 + 5;

vector<int> g[MAX_N];
vector<int> color;
bool bipartite;
int b, w;
void dfs(int u = 0, int c = 0) {
  color[u] = c;
  if (c) ++w;
  else ++b;
  for (int to : g[u]) {
    if (color[to] != -1) {
      if (color[to] == c) {
        bipartite = false;
        return;
      } else {
        continue;
      }
    }
    dfs(to, 1-c);
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  bipartite = true;
  color.assign(n, -1);
  dfs();
  ll ans = 1;
  if (bipartite) {
    ans = ans * b * w;
  } else {
    ans = ans * n * (n-1) / 2;
  }
  cout << ans-m << endl;
}
void solve(bool tests) {
  int t;
  cin >> t;
  while (t--) solve();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solve();
}