#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums) {
	int size = nums.size();

	if(size < 2) return size;

	int end = 0;

	for (int i = 1; i < size; ++i)
	{
		if (nums[i] != nums[end]) {
			nums[++end] = nums[i];
		}
	}
	return end+1;
}


int main() {
	int n;
	cin>>n;
	std::vector<int> v;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin>>temp;
		v.push_back(temp);
	}

	n = removeDuplicates(v);
	for (int i = 0; i < n; ++i)
	{
		cout<<v[i]<<' ';
	}
}