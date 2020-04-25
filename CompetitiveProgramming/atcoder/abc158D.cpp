#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  char c;
  int q, t, f = 0;
  cin >> s;
  cin >> q;
  bool is_front = true;
  vector<char> vf, vb;
  while (q--) {
    cin >> t;
    if (t == 1) {
      if (s.size() == 1 && f == 0) continue;
      is_front = !is_front;
    } else {
      cin >> f >> c;
      if (f == 1) {
        if (is_front) vf.push_back(c);
        else vb.push_back(c);
      } else {
        if (is_front) vb.push_back(c);
        else vf.push_back(c);
      }
    }
  }
  if (is_front) {
    for (auto it = vf.rbegin(); it != vf.rend(); ++it) cout << *it;
    cout << s;
    for (auto it = vb.begin(); it != vb.end(); ++it) cout << *it;
  } else {
    for (auto it = vb.rbegin(); it != vb.rend(); ++it) cout << *it;
    reverse(s.begin(), s.end());
    cout << s;
    for (auto it = vf.begin(); it != vf.end(); ++it) cout << *it;
  }
}