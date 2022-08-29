#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using vi = vector<int>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

const int MAX_N = 1000 + 5;
int cnt[MAX_N][MAX_N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  vector<string> maze(n);
  rep(i,n) cin >> maze[i];
  rep(i,n) {
    int now = 0;
    rep(j,6) {
      if (maze[i][j] == '#') ++now;
    }
    for (int j = 5; j < n; ++j) {
      if (j != 5) {
        if (maze[i][j-6] == '#') --now;
        if (maze[i][j] == '#') ++now;
      }
      if (now >= 4) {
        cout << "Yes\n";
        return 0;
      }
    }
  }
  rep(j,n) {
    int now = 0;
    rep(i,6) {
      if (maze[i][j] == '#') ++now;
    }
    for (int i = 5; i < n; ++i) {
      if (i != 5) {
        if (maze[i-6][j] == '#') --now;
        if (maze[i][j] == '#') ++now;
      }
      if (now >= 4) {
        cout << "Yes\n";
        return 0;
      }
    }
  }
  cout << "No\n";
  return 0;
}