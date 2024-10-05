#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;

const ll maxN = 1e6 + 4;
const ll INF = 1e18;
ll N, len, num;
ll lis[maxN];
pairll arr[maxN];
stack<ll> stk;


int main() {
	
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	fill(lis, lis + maxN, INF);

	for (ll i = 0; i < N; i++) {
		cin >> num;
		auto iter = lower_bound(lis, lis + len, num);
		if (*iter == INF) len++;
		*iter = num;
		ll idx = iter - lis;

		arr[i].first = idx;
		arr[i].second = num;
	}
	cout << len << "\n";

	for (int i = N - 1; i >= 0; i--) {
		if (len - 1 == arr[i].first) {
			len--;
			stk.push(arr[i].second);
		}
	}

	while (stk.size()) {
		cout << stk.top() << " ";
		stk.pop();
	}

	return 0;
}