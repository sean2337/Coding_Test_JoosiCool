#include<bits/stdc++.h>
using namespace std;

int N, d, p;
vector<pair<int, int>>vec;

bool cmt(pair<int, int>a, pair<int, int> b) {
	if (a.first > b.first) return true;
	return false;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> p >> d;
		vec.push_back({ d,p });
	}

	sort(vec.begin(), vec.end(), cmt);

	long long rnt = 0;
	priority_queue<int, vector<int>, less<int>>que;
	int j = 0;
	for (int day = 10000; day >= 1; day--) {
		
		while (j < N && day<=vec[j].first) {
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