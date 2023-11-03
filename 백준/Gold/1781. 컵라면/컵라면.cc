#include<bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, less<int>> que;
int N;
int a, b;
vector<pair<int, int>>vec;

bool tmp(pair<int, int>a, pair<int, int>b) {
	return a.first > b.first;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		vec.push_back({ a,b });
	}
	sort(vec.begin(), vec.end(),tmp);

	int j = 0;
	long long rnt = 0;
	for (int day = 200000; day >= 1; day--) {
		while (j < N && vec[j].first == day) {
			que.push(vec[j].second);
			j++;
		}
		if (que.size()) {
			rnt += que.top(); que.pop();
		}
	}

	cout << rnt;

	return 0;
}