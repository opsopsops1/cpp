// https://atcoder.jp/contests/abc236/tasks/abc236_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

int n, ans;
int a[20][20];
void dfs(vector<bool> s, int x) {
  int si = -1;
  rep(i,n) if (!s[i]) { si = i; break;}
  if (si == -1) {
    ans = max(ans, x);
    return;
  }
  
  s[si] = true;
  rep(i,n) {
    if (!s[i]) {
      s[i] = true;
      dfs(s, x^a[i][si]);
      s[i] = false;
    }
  }
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n;
  n *= 2;
  rep(i,n) {
    for (int j = i+1; j < n; ++j) {
      cin >> a[i][j];
      a[j][i] = a[i][j];
    }
  }

  vector<bool> s(n);
  dfs(s,0);
  cout << ans << endl;
  return 0;
}