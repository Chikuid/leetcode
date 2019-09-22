#include <iostream>
#include <vector>

using namespace std;


void reverseString(vector<char>& s) {
	int size = s.size();
	int j = size - 1;
	int i = 0;
	// char temp;

	while(i < size-1-i) {
		// temp = s[i];
		swap(s[i] , s[size-1-i]);
		// s[size-1-i] = temp;
		i++;
	}
	return;
}

//Large data types can provide an overloaded version of this function 
//optimizing its performance. Notably, all standard containers 
//specialize it in such a way that only a few internal pointers are 
//swapped instead of their entire contents, making them operate in constant time.

int main(int argc, char const *argv[])
{
	int size;
	cout<<"Enter size: ";
	cin>>size;

	vector<char> s;
	for(int i = 0; i<size; i++) {
		char c;
		cin>>c;
		s.push_back(c);
	}

	reverseString(s);

	for(int i = 0; i<size; i++) {
		cout<<s[i];
	}
	return 0;
}