#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include <algorithm>
#include<set>
#include <sstream>
#include <limits>
using namespace std;


int k;
char signArr[10];
bool visit[10] = { false };

long long vectorToInt(const std::vector<int>& vec) {
	long long result = 0;

	for (int i : vec) {
		result = result*10 + i;
	}

	return result;
}

//1: 맨 앞자리,2: 값
long long maxResult = numeric_limits<long long>::min();
long long minResult = numeric_limits<long long>::max();



void DFS(int idx, vector<int>&vec) {
	
	if (idx >= k) {
		maxResult = max(maxResult, vectorToInt(vec));
		minResult = min(minResult, vectorToInt(vec));
		return;
	}

	if (signArr[idx] == '<') {
		for (int nextValue = vec[vec.size() - 1]; nextValue < 10; nextValue++) {
			if (!visit[nextValue]) {
				visit[nextValue] = true;
				vec.push_back(nextValue);
				DFS(idx + 1, vec);
				visit[nextValue] = false;
				vec.pop_back();
			}
		}
	}
	else {
		for (int nextValue = vec[vec.size() - 1]; nextValue >=0; nextValue--) {
			if (!visit[nextValue]) {
				visit[nextValue] = true;
				vec.push_back(nextValue);
				DFS(idx + 1, vec);
				visit[nextValue] = false;
				vec.pop_back();
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> signArr[i];
	}


	for (int i = 0; i < 10; i++) {
		vector<int>vec;
		vec.push_back(i);
		visit[i] = true;

		DFS(0, vec);

		vec.pop_back();
		visit[i] = false;
	}

	string maxStr = to_string(maxResult);
	string minStr = to_string(minResult);

	if (minStr.size() == k) {
		minStr = '0' + minStr;
	}
	if (maxStr.size() == k) {
		maxStr = '0' + maxStr;
	}

	cout << maxStr << " " << minStr;

	return 0;
}