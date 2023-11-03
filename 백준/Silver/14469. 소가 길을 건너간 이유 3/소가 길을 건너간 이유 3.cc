#include<bits/stdc++.h>
using namespace std;

int N;
int a, b;
vector<pair<int, int>>vec;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		vec.push_back({ a,b });
	}
	sort(vec.begin(), vec.end());
	int cur = vec[0].first + vec[0].second;
	for (int i = 1; i < vec.size(); i++) {
		if (cur <= vec[i].first) {
			cur = vec[i].first + vec[i].second;
		}
		else {
			cur += vec[i].second;
		}
	}
	cout << cur;

	return 0;
}