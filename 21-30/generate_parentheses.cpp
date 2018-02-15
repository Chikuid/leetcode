#include <iostream>
#include <vector>
#include <string>

using namespace std;

void addPara(vector<string> &ans, string partial, int left, int right) {
	// left for no of opening brackets left 
	// right for no of closing brackets left
	if (right < left || right <0 || left < 0)
	{
		return;
	}

	else if (right == left && right == 0) {
		ans.push_back(partial);
	}

	else {	
		addPara(ans, partial + '(', left-1, right);
		addPara(ans, partial + ')', left, right-1);
	}
}

vector<string> generateParenthesis(int n) {
	vector<string> ans;
	addPara(ans, "", n, n);
	return ans;
}

int main() {
	int n;
	cin>>n;
	vector <string> ans = generateParenthesis(n);
	for (int i = 0; i < ans.size(); ++i)
	{
		cout<<ans[i]<<' ';
	}
}