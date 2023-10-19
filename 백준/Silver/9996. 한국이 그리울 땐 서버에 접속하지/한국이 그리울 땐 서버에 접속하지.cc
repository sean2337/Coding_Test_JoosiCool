#include<iostream>
#include<string>
#include<vector>
#include<array>
#include <limits>
#include<map>
#include<set>
#include<algorithm>
#include<regex>
using namespace std;
int main() {

	int T;

	cin >> T;
	string input;
	cin >> input;
	int starIndex = input.find('*');
	string regexStr = "^" + input.substr(0, starIndex) + ".*" + input.substr(starIndex+1) +"$";
	regex pattern(regexStr);

	while (T--) {
		cin >> input;
		if (regex_match(input, pattern)) {
			cout << "DA" << '\n';
		}
		else {
			cout<<"NE" << '\n';
		}
	}

	return 0;
}