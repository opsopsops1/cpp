#include <bits/stdc++.h>
using namespace std;

int main () {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, totaltime = 0, mintime = 1000;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    totaltime += v[i];
  }
  for (int i = 0; i < (1 << n); ++i) {
    bitset<4> b(i);
    int t = 0;
    for (int j = 0; j < n; ++j) {
      if (b.test(j)) t += v[j];
    }
    mintime = min(mintime, max(t, totaltime - t));
  }
  cout << mintime << endl;
}
