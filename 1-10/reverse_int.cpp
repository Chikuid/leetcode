#include <iostream>
#include <climits>
using namespace std;

int reverse(int x) {
  bool negative = false;
  if (x < 0) {
    x = x * -1;
    negative = true;
  }
  int ans = 0;
  while (x > 0) {
    if (ans > INT_MAX/10) {
      return 0;
    }
    if (ans == INT_MAX/10) {
      if (x%10 > INT_MAX%10) {
        return 0;
      }
    }
    ans = ans*10 + x%10;
    x = x/10;
  }
  if (negative) return ans*-1;
  return ans;
}

int main(){
  int n;
  cin>>n;
  std::cout << reverse(n) << '\n';
}
