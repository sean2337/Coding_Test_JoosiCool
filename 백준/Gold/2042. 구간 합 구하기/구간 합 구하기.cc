#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long, long long>pairLong;

ll N, M, K, a, b, c;
ll arr[1000004];
ll sumArr[1000004];

void update(ll idx, ll dif) {
	while (idx <= N) {
		sumArr[idx] += dif;
		idx += idx & (-idx);
	}
}

ll sum(ll idx) {
	ll result = 0;
	while (idx > 0) {
		result += sumArr[idx];
		idx -= idx & (-idx);
	}
	return result;
}


int main() {

	cin >> N >> M >> K;
	for (ll i = 1; i <= N; i++) {
		cin >> arr[i];
		update(i, arr[i]);
	}
	for (int i = 1; i <= M + K; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(b, c - arr[b]);
			arr[b] = c;
		}
		else {
			cout << sum(c) - sum(b - 1) << '\n';
		}
	}


	return 0;
}