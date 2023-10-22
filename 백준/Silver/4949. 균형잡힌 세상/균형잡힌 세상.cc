#include<bits/stdc++.h>
using namespace std;
bool isCheck(string str) {
	stack<char>stk;

	for (char c : str) {
		if (c == '(' || c == '[') {
			stk.push(c);
		}
		else if (c == ')') {
			if ( !stk.empty() && stk.top() == '(') {
				stk.pop();
			}
			else {
				return false;
			}
		}
		else if (c == ']') {
			if (!stk.empty() && stk.top() == '[') {
				stk.pop();
			}
			else {
				return false;
			}
		}
	}
	if (stk.empty()) return true;
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string str;
	while (true) {
		getline(cin, str);
		if (str == ".") break;
		if (isCheck(str)) {
			cout << "yes" << '\n';
		}
		else {
			cout << "no" << '\n';
		}
	}
	return 0;
};