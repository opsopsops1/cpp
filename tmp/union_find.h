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
  UnionFind tree(5);
  return 0;
}