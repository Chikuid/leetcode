#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector <int> &nums, int val) {
	int size = nums.size();
	if (size == 0) return 0;

	int count = 0;
	for (int i = 0; i < size; ++i)
	{
		if (nums[i] != val)
		{
			nums[count] = nums[i];
			count++;
		}
	}

	return count;
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
	
	int val;
	cin>>val;
	n = removeElement(v, val);

	for (int i = 0; i < n; ++i)
	{
		cout<<v[i]<<' ';
	}
	return 0;
}