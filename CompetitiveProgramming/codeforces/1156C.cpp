#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int n, z;
int a[N];

int main () {
  scanf("%d%d", &n, &z);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a, a + n);
  int l = 0, r = n / 2 + 1;
  while (r - l > 1) {
    int m = (l + r) / 2;
    bool good = true;
    for (int i = 0; i < m; ++i) {
      good &= (a[n - m + i] - a[i]) >= z;
    }
    if (good) l = m;
    else r = m;
  }
  printf("%d", l);
}

