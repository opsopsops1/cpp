// https://atcoder.jp/contests/abc157/tasks/abc157_d
#include <bits/stdc++.h>
using namespace std;

class UnionFind {
  vector<int> par, sz;
 public:
  UnionFind(int N) : par(N), sz(N) {
    for (int i = 0; i < N; ++i) par[i] = i;
    for (int i = 0; i < N; ++i) sz[i] = 1;
  }
  int root(int x) {
    if (par[x] == x) return x;
    return  par[x] = root(par[x]);
  }
  int size(int x) {
    return sz[root(x)];
  }
  bool same(int x, int y) {
    return root(x) == root(y);
  }
  void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return;
    if (sz[x] >= sz[y]) {
      sz[x] += sz[y];
      par[y] = x;
    } else {
      sz[y] += sz[x];
      par[x] = y;
    }
  }
};

int main() {
  int n, m, k;
  int a, b, c, d;
  cin >> n >> m >> k;
  UnionFind uf(n);
  vector<int> ans(n, -1);
  
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    --a, --b;
    uf.unite(a, b);
    --ans[a], --ans[b];
  }
  for (int i = 0; i < n; ++i) ans[i] += uf.size(i);
  for (int i = 0; i < k; ++i) {
    cin >> c >> d;
    --c, --d;
    if (uf.same(c, d) == false) continue;
    --ans[c], --ans[d];
  }
  
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " \n"[i == (n-1)];
  }
}
