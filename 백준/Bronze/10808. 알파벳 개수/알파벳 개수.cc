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
	for (char c : s) {
		arr[c - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		cout << arr[i] << ' ';
	}


	return 0;
}