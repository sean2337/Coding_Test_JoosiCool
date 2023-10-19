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


int main() {

	string s;
	string result = "";
	int T;
	cin >> T;
	while (T--) {
		cin >> s;
		
		arr[s[0] - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		if (arr[i] >= 5) {
			result += (char)(i + 'a');
		}

	}
	if (result.empty()) {
		cout << "PREDAJA";
	}
	else {
		cout << result;
	}

	return 0;
}