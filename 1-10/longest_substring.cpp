#include <iostream>
#include <map>
#include <string>
using namespace std;

int longestSubstring(std::string s) {
  map <char, int> last_pos;
  int max_len = 0, curr_len = 0, last_repeat = -1;
  int l = s.length();
  if (l == 0 || l == 1) return l;
  for (int i = 0; i<l; i++) {
    if (last_pos.find(s[i]) != last_pos.end()) {
      if (last_repeat < last_pos[s[i]]) {
        last_repeat = last_pos[s[i]];
      }
      curr_len = i - last_repeat;
      last_pos[s[i]] = i;
    }
    else {
      curr_len++;
      last_pos[s[i]] = i;
    }
    if (curr_len > max_len) max_len = curr_len;
  }
  return max_len;
}

int main() {
  string s;
  cin>>s;
  std::cout << "Lenght of maximum substring is "<< longestSubstring(s) << '\n';
  return 0;
}
