#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

const int MX = 2000;
vector<int> G[MX];
vector<bool> visited(MX);

void dfs(int f) {
  visited[f] = true;
  for (int t : G[f]) {
    if (visited[t]) continue;
    dfs(t);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  rep(i,m) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    G[a].push_back(b);
  }
  ll ans = 0;
  rep(i,n) {
    rep(j,n) visited[j] = false;
    dfs(i);
    rep(j,n) {
      if (visited[j]) ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}