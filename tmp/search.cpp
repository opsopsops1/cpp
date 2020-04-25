#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
const int n = 7;
int ans = 0;
int m[n+2][n+2];
int row[n+2], col[n+2];
int di[] = {1, 0, -1, 0};
int dj[] = {0, 1, 0, -1};

void search(int i, int j, int c) {
  if (i == n && j == n) {
    if (c == n*n) ++ans;
    return;
  }
  if (i < n && row[i] == n) {
    for (int id = i-1; id >= 1; --id) if (row[id] != n) return;
  }
  if (j < n && col[j] == n) {
    for (int id = j-1; id >= 1; --id) if (col[id] != n) return;
  }

  for (int d = 0; d < 4; ++d) {
    int ni = i + di[d];
    int nj = j + dj[d];
    if (ni < 1 || ni > n || nj < 1 || nj > n || m[ni][nj] == 1) continue;
    if (i == 1 && j == 1 && d == 1) continue;
    
    m[ni][nj] = 1;
    row[ni]++;
    col[nj]++;
    search(ni, nj, c+1);
    m[ni][nj] = 0;
    row[ni]--;
    col[nj]--;
  }
} 

int main(int argc, char *argv[]) {
  auto time_0 = clock();
  m[1][1] = 1;
  row[1] = 1;
  col[1] = 1;
  search(1, 1, 1);
  double time_1 = time(0);
  cout << ans*2 << "\n";
  cout << "spend time: " << float(clock() - time_0) / CLOCKS_PER_SEC << endl;
  return 0;
}