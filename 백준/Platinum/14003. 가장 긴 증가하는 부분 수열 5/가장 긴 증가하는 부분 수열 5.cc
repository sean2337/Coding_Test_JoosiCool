#define _CRT_SECURE_NO_WARNINGS 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;
const ll maxSize = 1e6 + 4;
const ll INF = 1e18;
ll N,len, K, M, T, num, a, b, c;
ll lis[maxSize];
pairll vec[maxSize];
stack<ll>stk;



int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(lis, lis + maxSize, INF);
	cin >> N;
	for (ll i = 0; i < N; i++) {
		cin >> num;
		auto pos = lower_bound(lis, lis + len, num);
		if (*pos == INF) len++;
		*pos = num;
		ll idx = ll(pos - lis);
		vec[i].first = idx;
		vec[i].second = num;
	}

	cout << len << '\n';

	for (ll i = N - 1; i >= 0; i--) {
		if (len - 1 == vec[i].first) {
			stk.push(vec[i].second);
			len--;
		}
	}

	while (stk.size()) {
		cout << stk.top() << " "; stk.pop();
	}

	return 0;
}