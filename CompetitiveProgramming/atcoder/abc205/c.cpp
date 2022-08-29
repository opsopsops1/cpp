#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int a, b, c;
  cin >> a >> b >> c;
  if (c%2 == 0) {
    a = abs(a);
    b = abs(b);
  } 
  if (a > b) cout << ">\n";
  else if (a < b) cout << "<\n";
  else cout << "=\n";
  return 0;
}