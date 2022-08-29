#include <iostream>
using namespace std;

int v[] = {1,3,5,7,11};

int binary_search(int i) {
  int l = -1, r = 5;
  while (r - l > 1) {
    int mid = (r + l) / 2;
    if (v[mid] <= i) l = mid;
    else r = mid;
  }
  return l;
}
int lower_bound_self(int i) {
  int l = -1, r = 5;
  while (r - l > 1) {
    int mid = (r + l) / 2;
    if (v[mid] >= i) r = mid;
    else l = mid;
  }
  return r;
}

int main() {
  // from left to right
  cout << binary_search(15) << endl; // 10
  cout << binary_search(10) << endl; // 8
  cout << binary_search(-5) << endl; // 0
  // from right to left
  cout << lower_bound_self(0) << endl;   // 0
  cout << lower_bound_self(5) << endl;   // 2
  cout << lower_bound_self(15) << endl;  // 4
  cout << lower_bound(v, v+5, 0)-v << endl;   // 0
  cout << lower_bound(v, v+5, 5)-v << endl;   // 2
  cout << lower_bound(v, v+5, 15)-v << endl;  // 5
}