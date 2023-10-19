#include<iostream>
#include<string>
#include<vector>
#include<array>
#include <limits>
#include<map>
#include<set>
#include<algorithm>
using namespace std;



int main() {

	int T;

	cin >> T;
	string input;
	cin >> input;
	int starIndex = input.find('*');
	string prefix = input.substr(0, starIndex);
	string suffix = input.substr(starIndex + 1);

	while (T--) {
		cin >> input;
		if (input.size() < prefix.size() + suffix.size()) {
			cout << "NE" << '\n';
			continue;
		}
		string prefixStr = input.substr(0, prefix.size());
		string suffixStr = input.substr(input.size()-suffix.size());

		if (prefix == prefixStr && suffix == suffixStr) {
			cout << "DA" << '\n';
		}
		else {
			cout << "NE" << '\n';
		}
	}

	return 0;
}