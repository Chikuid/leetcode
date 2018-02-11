#include <iostream>
#include <string>
using namespace std;

int romanToInt(string s) {
  s = s + 'S';   // Adding sentinel character in end
  int i = 0;     // Index variable
  int ans = 0;
  while(s[i] == 'M') {
    i++;
    ans += 1000;
  }
  while(s[i] == 'C' && s[i + 1] == 'M') {
    i += 2;
    ans += 900;
  }
  while(s[i] == 'D') {
    i++;
    ans += 500;
  }
  while(s[i] == 'C' && s[i+1] == 'D') {
    i += 2;
    ans += 400;
  }
  while(s[i] == 'C') {
    i++;
    ans += 100;
  }
  while(s[i] == 'X' && s[i+1] == 'C') {
    i += 2;
    ans += 90;
  }
  while(s[i] == 'L') {
    i++;
    ans += 50;
  }
  while(s[i] == 'X' && s[i+1] == 'L') {
    i += 2;
    ans += 40;
  }
  while(s[i] == 'X') {
    i++;
    ans += 10;
  }
  while(s[i] == 'I' && s[i+1] == 'X') {
    i += 2;
    ans += 9;
  }
  while(s[i] == 'V') {
    i++;
    ans += 5;
  }
  while(s[i] == 'I' && s[i+1] == 'V') {
    i += 2;
    ans += 4;
  }
  while(s[i] == 'I') {
    i++;
    ans += 1;
  }
  return ans;
}

int main() {
  string s;
  cin>>s;
  std::cout << romanToInt(s) << '\n';
}
