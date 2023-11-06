#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1003;
ll lis[1004];
pair<int, int>vec[1004];
ll N, num, len;

int main() {

	fill(lis, lis + 1004, INF);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		auto pos = lower_bound(lis, lis + len, num);
		ll idx = (int)(pos - lis);

		if (*pos == INF) len++;
		*pos = num;
	}
	cout << len;


	return 0;
}