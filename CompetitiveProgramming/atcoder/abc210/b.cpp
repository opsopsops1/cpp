#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  rep(i,n) {
    if (s[i] == '1') {
      if (i % 2 == 0) {
        cout << "Takahashi" << endl;
      } else {
        cout << "Aoki" << endl;
      }
      return 0;
    }
  }
  return 0;
}