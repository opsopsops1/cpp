// https://atcoder.jp/contests/abc165/tasks/abc165_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for(int i=0; i<(int)(n); ++i)

const int INF = 1234567890;
const int MAX_N = 200005;
vector<int> v, ans;
vector<int> g[MAX_N];
int dp[MAX_N];


void dfs(int from, int p=-1) {
  int i = lower_bound(dp, dp+MAX_N, v[from])-dp;
  int old = dp[i];
  dp[i] = v[from];
  ans[from] = i;
  if (p != -1) ans[from] = max(ans[from], ans[p]);
  for (auto to : g[from]) {
    if (to == p) continue;
    dfs(to, from);
  }
  dp[i] = old;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  v = ans = vector<int>(n);
  rep(i, n) cin >> v[i];
  rep(i, n-1) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  rep(i, MAX_N) dp[i] = INF;
  dp[0] = 0;
  dfs(0);
  rep(i, n) cout << ans[i] << endl;
}
