#include <iostream>
using namespace std;

int v[] = {1,3,5,7,11,12,13,15,20,22};

int bs(int i) {
  int l = -1, r = 10;
  while (r - l > 1) {
    int mid = (r + l) / 2;
    if (v[mid] <= i) l = mid;
    else r = mid;
  }
  return l;
}
int bs_2(int i) {
  int l = -1, r = 10;
  while (r - l > 1) {
    int mid = (r + l) / 2;
    if (v[mid] > i) r = mid;
    else l = mid;
  }
  return r;
}

int main() {
  cout << bs(-1) << endl;   // -1
  cout << bs(11) << endl;   // 4
  cout << bs(31) << endl;   // 9
  cout << bs_2(25) << endl; // 10
  cout << bs_2(15) << endl; // 8
  cout << bs_2(-5) << endl; // 0
  cout << *(lower_bound(v, v+10, -1)) << endl;  // 0
  cout << *(lower_bound(v, v+10, 11)) << endl;
  cout << *(lower_bound(v, v+10, 31)) << endl;  // no ptr
  // upper_bound = bs_2
}