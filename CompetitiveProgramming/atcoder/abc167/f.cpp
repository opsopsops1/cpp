// https://atcoder.jp/contests/abc167/tasks/abc167_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for(int i=0; i<(int)(n); ++i)

bool check(vector<P> v) {
  int h = 0;
  for (auto p : v) {
    int low = h + p.first;
    if (low < 0) return false;
    h += p.second;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, total = 0;
  string s;
  cin >> n;
  vector<P> l, r;
  rep(i, n) {
    cin >> s;
    int low = 0, h = 0;
    for(char c : s) {
      if (c == '(') ++h;
      else --h;
      low = min(low, h);
    }
    if (h > 0) l.emplace_back(low, h); else r.emplace_back(low-h, -h);
    total += h;
  }
  sort(l.rbegin(), l.rend());
  sort(r.rbegin(), r.rend());
  if (total == 0 && check(l) && check(r)) cout << "Yes\n";
  else cout << "No\n";
}