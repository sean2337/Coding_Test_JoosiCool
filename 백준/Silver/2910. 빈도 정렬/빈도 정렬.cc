#include<bits/stdc++.h>
using namespace std;


map<int, int> numMap;
map<int, int> orderMap;
int N, C;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return orderMap[a.first] < orderMap[b.first];
	}

	return a.second > b.second;
}

int main() {
	int num;
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> num;
		numMap[num]++;
		if (!orderMap[num]) orderMap[num] = i + 1;
	}

	vector<pair<int, int>> sortVec(numMap.begin(), numMap.end());
	sort(sortVec.begin(), sortVec.end(), cmp);

	for (auto v : sortVec) {
		for (int i = 0; i < v.second; i++) {
			cout << v.first << " ";
		}
	}

	return 0;
};