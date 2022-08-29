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
  int mx = 0;
  vi a(n);
  set<int> s;
  map<int, int> cnt;
  rep(i,n) cin >> a[i];
  rep(i,k) {
    s.insert(a[i]);
    cnt[a[i]] += 1;
  }
  mx = max<int>(mx, s.size());
  for (int i=k; i < n; ++i) {
    cnt[a[i-k]] -= 1;
    if (cnt[a[i-k]] == 0) s.erase(a[i-k]);
    s.insert(a[i]);
    cnt[a[i]] += 1;
    mx = max<int>(mx, s.size());
  }
  cout << mx << endl;
  return 0;
}