#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll len, N, num;
const ll maxNum = 1000004;
const ll INF = 1e9 + 4;
ll lis[maxNum];
pair<ll, ll>vec[maxNum];
stack<ll>stk;

int main() {
	fill(lis, lis + maxNum, INF);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		auto pos = lower_bound(lis, lis + len, num);
		int idx = (int)(pos - lis);
		if (*pos == INF) len++;
		*pos = num;
		vec[i].first = idx;
		vec[i].second = num;
	}

	cout << len << '\n';
	for (int i = N - 1; i >= 0; i--) {
		if (len - 1 == vec[i].first) {
			len--; stk.push(vec[i].second);
		}
	}
	
	while (stk.size()) {
		cout << stk.top() << " "; stk.pop();
	}

	return 0;
}