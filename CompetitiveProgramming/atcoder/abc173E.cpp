// https://atcoder.jp/contests/abc173/tasks/abc173_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

const int M = 1e9+7;
ll mul(ll a, ll b) { 
  a += M; a %= M;
  b += M; b %= M;
  return (a*b)%M;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  vector<int> pos, neg;
  rep(i,n) cin >> a[i];
  rep(i,n) {
    if (a[i] < 0) neg.push_back(a[i]);
    else pos.push_back(a[i]);
  }

  int ps = pos.size();
  int ns = neg.size();
  bool ok = false;
  if (ps > 0) {
    if (n == k) ok = (ns%2 == 0);
    else ok = true;
  } else {
    ok = (k%2 == 0);
  }

  ll ans = 1;
  if (!ok) {
    sort(a.begin(), a.end(), [] (int x, int y) {
      return abs(x) < abs(y);
    });
    rep(i,k) ans = mul(ans, a[i]);
  } else {
    sort(pos.begin(), pos.end());
    sort(neg.rbegin(), neg.rend());
    if (k%2 == 1) {
      ans = mul(ans, pos.back());
      pos.pop_back();
    }
    vector<ll> q;
    while (pos.size() >= 2) {
      ll tmp = pos.back();
      pos.pop_back();
      tmp *= pos.back();
      pos.pop_back();
      q.push_back(tmp);
    }
    while (neg.size() >= 2) {
      ll tmp = neg.back();
      neg.pop_back();
      tmp *= neg.back();
      neg.pop_back();
      q.push_back(tmp);
    }
    sort(q.rbegin(), q.rend());
    rep(i,k/2) ans = mul(ans, q[i]);
  }

  cout << ans << endl;
}