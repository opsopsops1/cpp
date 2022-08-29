#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i,n) cin >>a[i];
  priority_queue<int,vector<int>, greater<int>> que;
  rep(i,k) {
    que.push(a[i]);
  }
  cout << que.top() << endl;
  for (int i = k; i < n; ++i) {
    if (que.top() < a[i]) {
      que.pop();
      que.push(a[i]);
    }
    cout << que.top() << endl;
  }


  return 0;
}