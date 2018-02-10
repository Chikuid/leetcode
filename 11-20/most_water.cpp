#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector <int> &height) {
  int l = 0;
  int r = height.size() - 1;
  int max_area = 0;

  while(l < r) {
    int area = (r - l)*min(height[l], height[r]);
    if (area > max_area) {
      max_area = area;
    }
    if (height[l] < height[r]) {
      l++;
    }
    else {
      r--;
    }
  }
  return max_area;
}



int main() {
  int n;
  cin>>n;
  std::vector<int> v;
  for (int i = 0; i < n; i++) {
    int temp;
    cin>>temp;
    v.push_back(temp);
  }
  std::cout << maxArea(v) << '\n';
}
