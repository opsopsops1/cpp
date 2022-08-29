// https://atcoder.jp/contests/abc196/tasks/abc196_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

int h, w;
bool used[20][20];

int dfs(int i, int j, int a, int b) {
  if (a < 0 || b < 0) return 0;
  if (i == h) return 1;
  if (j == w) return dfs(i+1, 0, a, b);
  if (used[i][j]) return dfs(i, j+1, a, b);
  int res = 0;
  used[i][j] = true;
  res += dfs(i, j+1, a, b-1);
  if (i+1 < h && !used[i+1][j]) {
    used[i+1][j] = true;
    res += dfs(i, j+1, a-1, b);
    used[i+1][j] = false;
  }
  if (j+1 < w && !used[i][j+1]) {
    used[i][j+1] = true;
    res += dfs(i, j+1, a-1, b);
    used[i][j+1] = false;
  }
  used[i][j] = false;
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int a, b;
  cin >> h >> w >> a >> b;
  cout << dfs(0, 0, a, b) << endl;
  return 0;
}