#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for(int i=0; i<(int)(n); ++i)
ll a, b, c, d;
map<ll, ll> memo;

ll solve(ll n) {
  if (n == 0) return 0;
  if (n == 1) return d;
  if (memo.count(n)) return memo[n];
  
  ll res = 1e18;
  if (res/d > n) res = d*n;
  ll l2 = n/2*2;
  ll r2 = (n+1)/2*2;
  
  ll l3 = n/3*3;
  ll r3 = (n+2)/3*3;
  
  ll l5 = n/5*5;
  ll r5 = (n+4)/5*5;
  
  res = min(res, llabs(n-l2)*d + a + solve(l2/2));
  res = min(res, llabs(n-r2)*d + a + solve(r2/2));
  res = min(res, llabs(n-l3)*d + b + solve(l3/3));
  res = min(res, llabs(n-r3)*d + b + solve(r3/3));
  res = min(res, llabs(n-l5)*d + c + solve(l5/5));
  res = min(res, llabs(n-r5)*d + c + solve(r5/5));
  
  return memo[n] = res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll n;
    memo.clear();
    cin >> n >> a >> b >> c >> d;
    cout << solve(n) << endl;
  }
}