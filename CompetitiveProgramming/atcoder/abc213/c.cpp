#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int h, w, n;
  cin >> h >> w >> n;
  set<int> sa, sb;
  vector<int> a(n), b(n); 
  vector<int> va, vb;
  rep(i,n) {
    cin >> a[i] >> b[i];
    if (!sa.count(a[i])) {
      sa.insert(a[i]);
      va.push_back(a[i]);
    }
    if (!sb.count(b[i])) {
      sb.insert(b[i]);
      vb.push_back(b[i]);
    }
  }
  sort(va.begin(), va.end());
  sort(vb.begin(), vb.end());
  map<int, int> ma, mb;
  rep(i,va.size()) {
    ma[va[i]] = i+1;
  }
  rep(i,vb.size()) {
    mb[vb[i]] = i+1;
  }
  rep(i,n) {
    cout << ma[a[i]] << " " << mb[b[i]] << endl;
  }
  return 0;
}