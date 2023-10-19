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
	cin >> s;
	for (char c : s)
	{
		arr[c - 'A']++;
	}

	int oddNum = -1;
	for (int i = 0; i < 26; i++) {
		if (arr[i] % 2 == 1) {
			if (oddNum == -1) oddNum = i;
			else {
				cout << "I'm Sorry Hansoo";
				return 0;
			}
		}
	}

	if (oddNum!=-1) {
		arr[oddNum]--;
	}

	string result;
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < arr[i]/2; j++) {
			result += (i + 'A');
		}
	}
	string after = result;
	if (oddNum!=-1) {
		result += oddNum + 'A';
	}
	reverse(after.begin(), after.end());
	result += after;

	cout << result;


	return 0;
}