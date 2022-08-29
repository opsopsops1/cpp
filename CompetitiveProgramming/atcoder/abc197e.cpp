// https://atcoder.jp/contests/abc197/tasks/abc197_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

const int INF = 1001001001;
const ll IINF = 1ll<<60;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  vector<int> l(n, INF), r(n, -INF);
  rep(i,n) {
    int x, c;
    cin >> x >> c, --c;
    l[c] = min(l[c], x);
    r[c] = max(r[c], x);
  }
  vector<P> pos;
  pos.emplace_back(0, 0);
  rep(i,n) {
    if (l[i] == INF) continue;
    pos.emplace_back(l[i], r[i]);
  }
  pos.emplace_back(0, 0);
  // dp[0] = 累積到最左邊的點的最短路徑
  // dp[1] = 累積到最右邊的點的最短路徑
  vector<ll> dp(2);
  for (int i = 1; i < pos.size(); ++i) {
    vector<ll> now(2, IINF);
    swap(dp, now);
    int l = pos[i].first, r = pos[i].second;
    rep(j,2) {
      int x = j?pos[i-1].second:pos[i-1].first;
      dp[0] = min(dp[0], now[j]+abs(x-r)+(r-l));
      dp[1] = min(dp[1], now[j]+abs(x-l)+(r-l));
    }
  }
  cout << dp[0] << endl;
  return 0;
}