#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  
  // 1000
  // ^
  // |
  cout << __builtin_ffs(8) << endl;

  // 01010101
  // num of '1'
  cout << __builtin_popcount(1e9) << endl;
  
  return 0;
}