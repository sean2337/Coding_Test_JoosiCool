#include<bits/stdc++.h>
using namespace std;

long long N, from, to;
pair<long long, long long> vec[1000004];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> from >> to;
		vec[i]={ from, to };
	}

	sort(vec, vec+N);
	long long rnt = 0;
	for (int i = 0; i < N; i++) {
		from = vec[i].first; to = vec[i].second;
		while (true) {
			if (i + 1 < N && vec[i + 1].first >= from && vec[i + 1].first <= to) {
				to = max(to, vec[i + 1].second);
				i++;
			}
			else break;
		}
		rnt += (to - from);
	}

	cout << rnt;
	return 0;
}