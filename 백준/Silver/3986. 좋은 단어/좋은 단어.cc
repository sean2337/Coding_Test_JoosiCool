#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;



int main() {

	int T;
	int count = 0;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		stack<char>stk;
		for (char c : s) {
			if (stk.empty()) stk.push(c);
			else {
				if (stk.top() == c)
				{
					stk.pop();
				}
				else {
					stk.push(c);
				}
			}
		}
		if (stk.empty()) count++;
	}
	cout << count;
	
	return 0;
}