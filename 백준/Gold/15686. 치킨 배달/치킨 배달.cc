#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

vector<vector<int>>chickenList;
vector<pair<int, int>>chicken;
vector<pair<int, int>>home;
int m,n;

void combination(int start, vector<int>v) {
	if (v.size() == m) {
		chickenList.push_back(v);
		return;
	}

	for (int i = start+1; i < chicken.size();i++) {
		v.push_back(i);
		combination(i, v);
		v.pop_back();
	}

	return;
}



int main() {

	cin >> n >> m;
	int num;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> num;
			if (num == 1) {
				home.push_back({ i,j });
			}
			else if (num == 2) {
				chicken.push_back({ i,j });
			}
		}
	}
	vector<int>v;
	combination(-1, v);

	int result = 987654321;
	int calResult = 0;
	int homeCount = 987654321;
	for (vector<int>v : chickenList) {
		int count = 0;
		calResult = 0;
		for (pair<int, int> homeValue : home) {
			homeCount = 987654321;
			for (int chickenIndex : v) {
				homeCount = min(homeCount, abs(chicken[chickenIndex].first - homeValue.first) + abs(chicken[chickenIndex].second - homeValue.second));
			}
			calResult += homeCount;
		}
		result = min(result, calResult);

	}
	cout << result << '\n';
	return 0;
}