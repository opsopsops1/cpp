#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int n, x[N], y[N];
map<pair<int, int>, set<long long> > slopeM;

int main () {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &x[i], &y[i]);
  }
  long long ans = 0, total = 0;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int x1 = x[i], x2 = x[j], y1 = y[i], y2 = y[j];
      int a = y1 - y2, b = x1 - x2;
      int g = __gcd(a, b); a /= g; b /= g;
      if (a < 0 || (a == 0 && b < 0)) {
        a = -a; b = -b;
      }
      pair<int, int> p(a, b);
      long long c = a * x1 - b * y1;
      if (!slopeM[p].count(c)) {
        ++total;
        slopeM[p].insert(c);
        ans += total - slopeM[p].size();
      }
    }
  }
  printf("%lld", ans);
}
