#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> letterCombinations(string digits) {
	vector<string> ans;
	int len = digits.length();
	if (len < 1)
	{
		return ans;
	}
	ans.push_back("");
	vector<string> next_line;


	//Storing size of char arrays note the difference in indexes
	//two is mapped to index 0 and so on
	const int size_array[8] = {3, 3, 3, 3, 3, 4, 3, 4};
	const string mappings[8] = { {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'},\
	 {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, \
{'w', 'x', 'y', 'z'} };
	// const char two[3]		= {'a', 'b', 'c'};
	// const char three[3] 	= {'d', 'e', 'f'};
	// const char four[3]		= {'g', 'h', 'i'};
	// const char five[3]		= {'j', 'k', 'l'};
	// const char six[3]		= {'m', 'n', 'o'};
	// const char seven[4]		= {'p', 'q', 'r', 's'};
	// const char eight[3]		= {'t', 'u', 'v'};
	// const char nine[4]		= {'w', 'x', 'y', 'z'};

	for (int i = 0; i < len; ++i)
	{
		int val = digits[i] - '0';
		int shifted_val = val - 2;

		if (val < 0) {
			cout<<"Error in parsing unexpected char" << digits[i];
			return ans;
		}
		else {
			int possibilites = size_array[shifted_val];
			for (int j = 0; j < possibilites; ++j)
			{
				int curr_ans_length = ans.size();
				for (int k = 0; k < curr_ans_length; ++k)
				{
					next_line.push_back(ans[k] + mappings[shifted_val][j]);
				}
			}
		}
		ans = next_line;
		next_line.clear();
	}
	return ans;
}


int main() {
	string s;
	cin>>s;
	std::vector<string> v = letterCombinations(s);
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i]<<'\n';
	}
	return 0;
}