#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1003;
ll lis[1004];
pair<int, int>vec[1004];
ll N, num, len;
stack<ll>stk;

int main() {

	fill(lis, lis + 1004, INF);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		auto pos = lower_bound(lis, lis + len, num);
		ll idx = (int)(pos - lis);

		if (*pos == INF) len++;
		*pos = num;
		vec[i].first = idx;
		vec[i].second = num;
	}

	cout << len << '\n';

	for (int i = N - 1; i >= 0; i--) {
		if (vec[i].first == len - 1) {
			stk.push(vec[i].second); len--;
		}
	}

	while (stk.size()) {
		cout << stk.top() << " "; stk.pop();
	}
	return 0;
}