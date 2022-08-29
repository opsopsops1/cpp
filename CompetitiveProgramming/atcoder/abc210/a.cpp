#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, a, x, y;
  cin >> n >> a >> x >> y;
  int ans = x*n;
  if (n > a) ans -= (n-a)*(x-y);
  cout << ans << endl;
  return 0;
}