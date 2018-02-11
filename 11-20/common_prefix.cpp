#include <iostream>
#include <string>
#include <vector>
using namespace std;


string longestCommonPrefix(vector<string> &strs) {
  int count = strs.size();
  string common;
  int common_length;

  if (!strs.empty()) {
    common = strs[0];
    common_length = common.length();
  }
  else {
    common = "";
  }

  int curr_length;
  for (int i = 1; i<count; i++) {
    curr_length = 0;
    for (int j = 0; j < common_length; j++) {
      if (strs[i][j] != common[j]){
        break;
      }
      curr_length++;
    }
    if (curr_length < common_length) {
      common_length = curr_length;
    }
  }

  return common.substr(0, common_length);
}

int main() {
  int n;
  cin>>n;
  vector <string> strs;
  for (size_t i = 0; i < n; i++) {
    string temp;
    cin>>temp;
    strs.push_back(temp);
  }

  std::cout << longestCommonPrefix(strs) << '\n';
}
