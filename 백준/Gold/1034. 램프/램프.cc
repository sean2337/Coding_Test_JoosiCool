#include<iostream>
#include<queue>
#include <utility>
#include<map>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<string, int> map;

	int N, M, K;
	cin >> N >> M;
	vector<string> vec;
	string s;

	for (int i = 0; i < N; i++) {
		cin >> s;
		vec.push_back(s);
	}

	cin >> K;

	for (int i = 0; i < vec.size(); i++) {
		int zeroCnt = 0;
		for (int sLen = 0; sLen < vec[i].size(); sLen++) {
			if (vec[i][sLen] == '0') zeroCnt++;
		}
		if (zeroCnt <= K && (K - zeroCnt) % 2 ==0) map[vec[i]]++;
	}

	int rnt = 0;
	for (auto iter : map) {
		rnt = max(rnt, iter.second);
	}

	cout << rnt;

	return 0;
}