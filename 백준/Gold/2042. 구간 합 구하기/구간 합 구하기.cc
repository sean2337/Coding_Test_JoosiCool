#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxNum = 1e6 + 4;
ll arr[maxNum], tree[maxNum];
ll N, M, K;

ll getSum(ll idx) {
	ll result = 0;
	while (idx > 0) {
		result += tree[idx];
		idx -= (idx & -idx);
	}
	return result;
}

void update(ll idx, ll dif) {
	while (idx <= N) {
		tree[idx] += dif;
		idx += (idx & -idx);
	}
}


int main() {

	cin >> N >> M >> K;
	for (ll i = 1; i <= N; i++) {
		cin >> arr[i];
		update(i, arr[i]);
	}

	ll a, b, c;
	for (ll i = 1; i <= M + K; i++) {
		cin >> a >> b >> c;
		if(a==1){
			ll dif = c - arr[b];
			arr[b] = c;
			update(b, dif);
		}
		else {
			cout << getSum(c) - getSum(b - 1) << '\n';
		}
	}
	return 0;
}