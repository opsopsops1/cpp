#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(false);
  long long u, v;
  cin >> u >> v;
  if (u == v) {
    if (u) {
      cout << "1\n" << u << endl;
    } else {
      cout << "0\n";
    }
  } else if (u > v || (v-u)%2) {
    cout << "-1\n";
  } else {
    if ((((v-u)/2) ^ ((v+u)/2)) == u) {
      cout << "2\n" << (v-u)/2 << " " << (v+u)/2 << endl;
    } else {
      cout << "3\n" << u << " " << (v-u)/2 << " " << (v-u)/2 << endl;
    }
  }
}