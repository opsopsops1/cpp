// https://atcoder.jp/contests/abc239/tasks/abc239_e
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using vi = vector<int>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> x(n);
  rep(i,n) cin >> x[i];
  vector<vector<int>> to(n);
  rep(i,n-1) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  vector<vector<pair<int, int>>> qs(n);
  rep(i,q) {
    int v, k;
    cin >> v >> k;
    --v; --k;
    qs[v].emplace_back(k, i);
  }
  vector<int> ans(q);
  const int K = 20;
  auto merge = [&] (vector<int>& a, const vector<int>& b) {
    a.insert(a.end(), b.begin(), b.end());
    sort(a.rbegin(), a.rend());
    a.resize(K);
  };
  auto dfs = [&] (auto f, int u, int p=-1) -> vector<int> {
    vector<int> res(K);
    res[0] = x[u];
    for (auto v : to[u]) {
      if (v == p) continue;
      auto d = f(f, v, u);
      merge(res, d);
    }
    for (auto [k, i] : qs[u]) {
      ans[i] = res[k];
    }
    return res;
  };
  dfs(dfs, 0);
  rep(i,q) {
    cout << ans[i] << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t = 1;
  // cin >> t;
  rep(_,t) solve();
  return 0;
}