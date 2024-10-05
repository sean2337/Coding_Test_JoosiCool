#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;

const ll maxN = 1e6 + 4;
const ll INF = 1e18;

ll lis[maxN];
ll N, len, num;
pairll arr[maxN];

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(lis, lis + maxN, INF);

	cin >> N;
	for (ll i = 0; i < N; i++) {
		cin >> num;
		auto pos = lower_bound(lis, lis + len, num);
		if (*pos == INF) len++;
		*pos = num;
		ll idx = pos - lis;
		arr[i].first = idx;
		arr[i].second = num;
	}

	cout << len << "\n";

	stack<ll> stk;

	for (ll i = N - 1; i >= 0; i--) {
		if (arr[i].first == len - 1) {
			stk.push(arr[i].second);
			len--;
		}
	}

	while (stk.size()) {
		cout << stk.top() << " ";
		stk.pop();
	}

	return 0;
}