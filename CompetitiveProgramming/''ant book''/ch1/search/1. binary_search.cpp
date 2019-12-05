#include <bits/stdc++.h>
using namespace std;

int digit(int i) {
  int d = 0;
  while (i) {
    i /= 10;
    ++d;
  }
  return d;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long a, b, x, price;
  int mid, l = 0, r = 1000000001;
  cin >> a >> b >> x;
  while (r - l > 1) {
    mid = (r + l) / 2;
    price = a * mid + b * digit(mid);
    if (price <= x) l = mid;
    else r = mid;
  }
  cout << l << endl;
}
