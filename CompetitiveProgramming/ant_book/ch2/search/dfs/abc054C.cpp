// https://atcoder.jp/contests/abc054/tasks/abc054_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i=0; i<(int)(n); ++i)
#define rep2(i, a, b) for(int i=a; i<=(int)(b); ++i)
#define all(v) v.begin(),v.end()

vector<vector<int>> g;

int n, ans;

void dfs(int u, int v) {
  v = v | (1 << u);
  if (v+1 == (1 << n)) ++ans;
  for (int to : g[u]) {
    if (v & (1 << to)) continue;
    dfs(to, v);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int m;
  cin >> n >> m;
  g.resize(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0, 0);
  cout << ans << endl;
}