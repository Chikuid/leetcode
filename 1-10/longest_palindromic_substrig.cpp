#include <iostream>
#include <math.h>
#include <string>
#include <utility>
#include <cstdlib>
using namespace std;

pair<int, int> longestPalindromeAroundPivot(string s, float pivot, \
  bool doublePivot) {
  int a, b;
  // doublePivot is true when two chars are pivot
  if (!doublePivot) {
    a = pivot - 1;
    b = pivot + 1;
  }
  else {
    a = pivot;
    b = pivot + 1;
  }
  int l = s.length();
  if (l == 1) return make_pair(0, 0); // Corner case

  while (a >= 0 && b < l) {
    if (s[a] != s[b]) {
      if (b-a == 1) { // It is the first comparison for doublePivot case
        return make_pair(0, 0);
      }
      else {
        return make_pair(a+1, b-1);
      }
    }
    a--;
    b++;
  }
  return make_pair(a + 1, b - 1);
}

string longestPalindrome(string s) {
  int max_len = 0;
  pair<int, int> ans;
  ans = make_pair(0, 0);
  pair<int, int> temp;
  int l = s.length();
  for (int i = 0; i < l; i++) {
    cout<<i<<'\n';
    cout<<"false"<<' ';
    temp = longestPalindromeAroundPivot(s, i, false);
    cout<<"Return value: "<<temp.first<<' '<<temp.second<<'\n';
    if ((temp.second - temp.first) > max_len) {
      ans = temp;
      max_len = temp.second - temp.first;
    }
    cout<<"true"<<'\n';
    temp = longestPalindromeAroundPivot(s, i, true);
    cout<<"Return value: "<<temp.first<<' '<<temp.second<<'\n';
    if ((temp.second - temp.first) > max_len) {
      ans = temp;
      max_len = temp.second - temp.first;
    }
  }
  cout<<"Answer: "<<ans.first<<' '<<ans.second;
  return s.substr(ans.first, max_len + 1);
}

int main() {
  string s;
  cin>>s;
  std::cout << longestPalindrome(s) << '\n';
  return 0;
}
