#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int numways(string s) {
  int ans = 1, L = s.length();

  if (L % 2 == 0 || L == 1) return 1;

  // ABC -> AB + ABC
  if (s.substr(0,L/2) == s.substr(L/2,L/2))
    ans += numways(s.substr(L/2,L/2+1));
  
  // ABC -> ABC + AB
  if (s.substr(0,L/2) == s.substr(L/2+1,L/2))
    ans += numways(s.substr(0,L/2+1));
  
  // ABC -> BC + ABC
  if (s.substr(0,L/2) == s.substr(L/2+1,L/2))
    ans += numways(s.substr(L/2,L/2+1));

  // ABC -> ABC + BC
  if (s.substr(1,L/2) == s.substr(L/2+1,L/2))
    ans += numways(s.substr(0,L/2+1));

  return ans;
}

int main() {
  string s;

  cin >> s;
  cout << numways(s) - 1 << endl;

  return 0;
}