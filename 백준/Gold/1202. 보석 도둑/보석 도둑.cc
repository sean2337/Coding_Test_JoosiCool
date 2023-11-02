#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>>vec;
vector<int>bagVec;

int N, K, m, v;


int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> m >> v;
		vec.push_back({m,v });
	}
	for (int i = 0; i < K; i++) {
		cin >> m;
		bagVec.push_back(m);
	}

	sort(vec.begin(), vec.end());
	sort(bagVec.begin(), bagVec.end());


	priority_queue<int> pq;
	long long rnt = 0;
	int j = 0;
	for (int i = 0; i < bagVec.size(); i++) {
		while (j < N && vec[j].first <= bagVec[i]) {
			pq.push(vec[j].second);
			j++;
		}

		if (pq.size()) {
			rnt += pq.top();
			pq.pop();
		}
	}
	cout << rnt;
	return 0;
}