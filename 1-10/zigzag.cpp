#include <iostream>
#include <string>

using namespace std;

string convert(string s, int numRows) {
  if (numRows == 1) return s;
  int l = s.length();
  string ans = "";
  for (int i = 0; i < numRows; i++) {
    int pos = i;
    ans += s[pos];
    int jump1 = 2*(numRows - i - 1);
    int jump2 = 2*i;
    while(pos < l) {
      if(jump1 > 0) {
        pos = pos + jump1;
        if (pos >= l) {
          break;
        }
        ans += s[pos];
      }
      if(jump2 > 0) {
        pos = pos + jump2;
        if (pos >= l) {
          break;
        }
        ans += s[pos];
      }
    }
  }
  return ans;
}

int main() {
  string s;
  int n;
  cin>>s;
  cin>>n;
  std::cout << convert(s, n) << '\n';
  return 0;
}
