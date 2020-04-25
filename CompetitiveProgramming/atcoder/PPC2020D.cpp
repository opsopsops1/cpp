#include <bits/stdc++.h>
using namespace std;
int n;

void dfs(string s, char mx){
  if(s.length() == n){
    printf("%s\n", s.c_str());
  } else {
    for(char c='a'; c<= mx; c++){
      dfs(s + c, ((c == mx) ? (char)(mx + 1) : mx));
    }
  }
}

int main() {
  cin >> n;
  dfs("", 'a');
}