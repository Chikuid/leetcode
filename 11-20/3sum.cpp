#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printArray(std::vector<int> v) {
  int count = v.size();
  for (size_t i = 0; i < count; i++) {
    std::cout << v[i] << '\n';
  }
}

vector<vector<int> > threeSum(vector<int> &nums) {
  sort(nums.begin(), nums.end());
  int size = nums.size();
  vector<vector<int> > ans;

  int a, b, c;
  int i = 1;

  while(i < size-1) {
    b = i;
    a = i-1;
    c = i+1;
    while(a>=0 && c<size) {
      if ((nums[a] + nums[b] + nums[c]) == 0) {
        vector<int> triplet;
        triplet.push_back(nums[a]);
        triplet.push_back(nums[b]);
        triplet.push_back(nums[c]);
        ans.push_back(triplet);
      }
      if ((nums[a] + nums[b] + nums[c]) > 0) {
        a--;
        while(a > 0 && nums[a] == nums[a+1]){
          a--;
        }
      }
      else {
        c++;
        while(c<size-1 && nums[c] == nums[c-1]) {
          c++;
        }
      }
    }
    i++;
  }
  sort(ans.begin(), ans.end());
  ans.erase(unique(ans.begin(), ans.end()), ans.end());
  return ans;
}

int main() {
  int n, x;
  std::cout << "Enter the size of input array: " << '\n';
  std::cin >> n;
  std::vector<int> nums;
  std::cout << "Now enter the numbers: " << '\n';
  for (size_t i = 0; i < n; i++) {
    std::cin >> x;
    nums.push_back(x);
  }

  std::vector<std::vector<int> > ans = threeSum(nums);
  int count = ans.size();

  std::cout << "Output is: " << '\n';
  for (size_t i = 0; i < count; i++) {
    std::cout << ans[i][0] << " "<< ans[i][1]<<" "<< ans[i][2]<<"\n";
  }
  return 0;
}
