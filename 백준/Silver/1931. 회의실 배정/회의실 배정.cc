#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>>vec;
int from, to;
int N;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> from >> to;
		vec.push_back({ to,from });
	}

	sort(vec.begin(), vec.end());
	int rnt = 1;
	tie(to, from) = vec[0];
	for (int i = 1; i < N; i++) {
		if (to <= vec[i].second) {
			from = vec[i].second;
			to = vec[i].first;
			rnt++;
		}
	}
	cout << rnt;

	return 0;
}