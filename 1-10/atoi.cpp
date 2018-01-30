#include <iostream>
#include <climits>

using namespace std;


int myVal(char a) {
  if (a >= '0' && a <= '9') {
    return a - '0';
  }
  if (a == '-') return -2;
  if (a == '+') return -3;
  if (a == ' ') return -4;
  return -1;
}

int myAtoi(string str) {
  long ans = 0;
  int count = str.length();
  bool touched = false;
  bool negative = false;
  for (int i = 0; i < count; i++) {
    int val = myVal(str[i]);

    if (val != -1) {

      if (val == -2) {
         if (touched) return ans;
         negative = true;
         touched = true;
      }

      else if (val == -3) {
         if (touched) return ans;
         touched = true;
      }

      else if (val == -4) {
        if (touched) return ans;
      }

      else{
        touched = true;
        ans = ans*10 + val;
        if (ans > INT_MAX) {
            if (negative) {
                return INT_MIN;
            }
            return INT_MAX;
        }
      }
    }

    else {
      break;
    }

  }
  if (negative) ans = ans * -1;
  if (ans > INT_MAX) return INT_MAX;
  if (ans < INT_MIN) return INT_MIN;
  return ans;
}

int main() {
  string s;
  cin>>s;
  std::cout << myAtoi(s) << '\n';
}
