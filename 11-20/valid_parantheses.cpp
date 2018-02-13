#include <iostream>
#include <stack>
#include <map>
using namespace std;

bool isValid(string s){
	int len = s.length();
	stack <char> brackets;
	map <char, char> matchs;
	matchs['}'] = '{';
	matchs[']'] = '[';
	matchs[')'] = '(';

	for (int i = 0; i < len; ++i)
	{
		if (s[i] == '{' || s[i] == '(' || s[i] == '[')
		{	brackets.push(s[i]);
		}
		else
		{	if (!brackets.empty() && matchs.find(s[i]) != matchs.end() && matchs[s[i]] == brackets.top())
			{
				brackets.pop();
			}
			else
			{
				return false;
			}
		}
	}
	if(brackets.empty()) return true;
	return false;
} 


int main() {
	string s;
	cin>>s;
	cout<<isValid(s)<<'\n';
}