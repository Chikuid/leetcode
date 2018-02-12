#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

void printArray(std::vector<int> v) {
  int count = v.size();
  for (size_t i = 0; i < count; i++) {
    std::cout << v[i] << '\n';
  }
}

int threeSumClosest(vector<int> &nums, int target) {
  sort(nums.begin(), nums.end());
  int size = nums.size();
  if (size <= 2) {
    return 0;
  }

  int ans = nums[0] + nums[1] + nums[2];

  int a, b, c;
  int i = 1;

  while(i < size-1) {
    b = i;
    a = i-1;
    c = i+1;
    while(a>=0 && c<size) {
      if (abs((nums[a] + nums[b] + nums[c]) - target) < abs(ans-target)) {
        ans = nums[a] + nums[b] + nums[c];
      }
      if ((nums[a] + nums[b] + nums[c]) > target) {
        a--;
      }
      else {
        c++;
      }
    }
    i++;
  }
  return ans;
}

int main() {
  int n, x, target;
  std::cout << "Enter the size of input array: " << '\n';
  std::cin >> n;
  std::vector<int> nums;
  std::cout << "Now enter the numbers: " << '\n';
  for (size_t i = 0; i < n; i++) {
    std::cin >> x;
    nums.push_back(x);
  }
  std::cout << "Enter the target number: " << '\n';
  cin>>target;

  int ans = threeSumClosest(nums, target);

  std::cout << "Output is: " << ans;
  return 0;
}
