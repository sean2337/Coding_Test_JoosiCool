#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	string s;
	cin >> s;
	string before = s.substr(0,s.size()/2);
	reverse(s.begin(), s.end());
	if (before == (s.substr(0, s.size() / 2))) cout << 1;
	else cout << 0;
	return 0;
}