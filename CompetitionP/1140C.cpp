#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < n; ++i)
#define ll long long
#define mp make_pair
#define pb push_back
using namespace std;

int main () {
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);

  int n, k;
  cin >> n >> k;
  vector<pair<int, int> > s(n);
  for (auto &ss : s) cin >> ss.second >> ss.first;
  sort(s.rbegin(), s.rend());
  //for (auto &ss : s) cout << ss.second << " " << ss.first << "\n";
  ll ans = 0, sum = 0;
  multiset<int> pl;
  for (auto &ss : s) {
    pl.insert(ss.second);
    sum += ss.second;
    if (pl.size() > k) {
      auto it = pl.begin();
      sum -= *it;
      pl.erase(it);
    }
    ans = max(ans, sum * ss.first);
  }
  cout << ans << endl;
}
