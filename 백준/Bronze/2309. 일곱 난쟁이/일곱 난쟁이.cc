#include<iostream>
#include<string>
#include<vector>
#include<array>
#include <limits>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

int n = 9;
int k = 7;
int arr[9];


void combination(int start, vector<int>vec) {
	if (vec.size() == k) {
		int sum = 0;
		for (int c : vec) {
			sum += arr[c];
		}
		if (sum != 100) return;
		vector<int> sortVec;
		for (int c : vec) {
			cout << arr[c] << '\n';
		}
		exit(0);
		return;
	}

	for (int i = start+1; i < n; i++) {
		vec.push_back(i);
		combination(i, vec);
		vec.pop_back();
	}
}

int main() {

	vector<int>vec;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + 9);
	
	combination(-1, vec);

	return 0;
}