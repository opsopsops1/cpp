#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

const int MX = 1005;
int A[MX][MX];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int h, w, c;
  cin >> h >> w >> c;
  ll miin = 1ll<<60;
  rep(i,h)rep(j,w) cin >> A[i][j];
  
  return 0;
}