#include <bits/stdc++.h>
#define rep(i, n)  for(int i = 0; i < n; ++i)
#define ll         long long
#define mp         make_pair
#define pb         push_back
using namespace std;

int ans[6];

int main () {
  ios::sync_with_stdio(0), cin.tie(0);

  vector<int> a = {4, 8, 15, 16, 23, 42};
  for (int i = 1; i < 5; ++i) {
    cout << "? 1 " << (1 + i) << endl;
    fflush(stdout);
    cin >> ans[i];
  }
	do {
	  bool ok = true;
	  for (int i = 1; i < 5; ++i) {
	    if (a[0] * a[i] != ans[i]) ok = false;
    }
    if (ok) {
      break;
    }
  } while (next_permutation(a.begin(), a.end()));  // must have answer
  cout << "!";
  for (int x : a) {
    cout << " " << x;
  }
  cout << endl;
}





