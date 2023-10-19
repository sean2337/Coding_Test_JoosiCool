#include<iostream>
#include<string>
#include<vector>
#include<array>
#include <limits>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

int arr[26];


char ROT13(char c) {
	int i = (int)c;
	if (i >= 65 && i <= 90) {
		i += 13;
		if (i > 90) {
			i -= 26;
		}
	}
	else if (i >= 97 && i <= 122) {
		i += 13;
		if (i > 122) {
			i -= 26;
		}
	}

	return i;
}

int main() {
	string s;
	getline(cin, s);
	string result = "";

	for (char c : s) {
		if (c >= 'A' && c <= 'z') {
			result += ROT13(c);
		}
		else {
			result += c;
		}
	}
	cout << result << '\n';
	return 0;
}