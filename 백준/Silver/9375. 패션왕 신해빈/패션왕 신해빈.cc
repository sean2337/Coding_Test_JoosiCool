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

	int T, N;
	string str1, str2;
	cin >> T;

	while (T--) {
		map<string, int> mp;
		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> str1 >> str2;
			mp[str2]++;
		}
		int result = 1;
		for (auto it : mp) {
			result *= (it.second+1);
		}
		cout << result - 1 << endl;
	}

	return 0;
}