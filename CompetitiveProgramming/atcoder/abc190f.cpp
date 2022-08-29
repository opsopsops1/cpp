// inversion numbers by order set
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)
#define rrep(i,n) for(int i=1; i<=(int)(n); ++i)

template<class T>
using order_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  vi a(n);
  for (auto &x : a) cin >> x;

  order_set<int> s;
  ll ans = 0;
  for (auto x : a) {
    ans += (s.size() - s.order_of_key(x));
    s.insert(x);
  }
  rep(i,n) {
    cout << ans << endl;
    ans = ans - a[i] + (n-1-a[i]);
  }
  
  return 0;
}