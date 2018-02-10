#include <iostream>
using namespace std;

bool isPalindrome(int x) {
  if (x < 0) {
    return false;
  }
  if (x %10 == 0 ){
      if (x == 0) return true;
      return false;
  }
  int clipped = 0;
  while (clipped <= x) {
    int temp = x%10;
    x = x/10;
    if (x == clipped) return true;
    clipped = clipped * 10 + temp;
    if (x == clipped) return true;
  }
  return false;
}

int main() {
  int n;
  cin>>n;
  std::cout << isPalindrome(n) << '\n';
}
