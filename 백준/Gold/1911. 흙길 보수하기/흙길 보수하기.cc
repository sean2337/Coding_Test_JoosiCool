#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pairInt;

vector<pairInt> vec;
int N, L, s, e;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		cin >> s >> e;
		vec.push_back({ s,e });
	}
	sort(vec.begin(), vec.end());
	int cnt = 0, idx = 0, plus;
	for (int i = 0; i < N; i++) {
		if (idx >= vec[i].second) continue;
		if (idx < vec[i].first) {
			plus = (vec[i].second - vec[i].first) / L + ((vec[i].second - vec[i].first) % L ? 1 : 0);
			idx = vec[i].first + plus * L;
		}
		else {
			plus = (vec[i].second - idx) / L + ((vec[i].second - idx) % L ? 1 : 0);
			idx = idx + plus * L;
		}
		cnt += plus;
	}
	cout << cnt;
	

	return 0;
}
