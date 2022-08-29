// https://atcoder.jp/contests/aising2020/tasks/aising2020_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for(int i=0; i<(int)(n); ++i)

int pc(int x) {
  return __builtin_popcount(x);
}
int f(int x) {
  return (x == 0)?0:(f(x%pc(x))+1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  string s;
  cin >> s;
  int cnt = 0;
  vector<int> bin(n);
  rep(i, n) bin[i] = s[i]-'0';
  rep(i, n) cnt += bin[i];

  vector<int> ans(n);
  rep(b, 2) {
    int ncnt = cnt;
    if (b == 0) ++ncnt;
    else --ncnt;
    if (ncnt <= 0) continue;

    int base = 0;
    rep(i, n) {
      base = base*2%ncnt;
      base += bin[i];
    }
    int two = 1;
    for (int i = n-1; i >= 0; --i) {
      if (bin[i] == b) {
        int nb = base;
        if (b == 0) nb = (nb+two)%ncnt;
        else nb = (nb+ncnt-two)%ncnt;
        ans[i] = f(nb)+1;
      }
      two = (two*2)%ncnt;
    }
  }
  rep(i, n) cout << ans[i] << endl;
}