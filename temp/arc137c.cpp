// https://atcoder.jp/contests/arc137/tasks/arc137_c#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  if (a[n-1] > a[n-2]+1) cout << "Alice" << endl;
  else {
    if ((a[n-1]-n-1)&1) cout << "Alice" << endl;
    else cout << "Bob" << endl;
  }
  return 0;
}