#define _CRT_SECURE_NO_WARNINGS 
#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;
ll visited[10004];
const ll INF = 987654321;
ll N, K, M, num;
ll a, b, c;
const ll maxNum = 1e6 + 4;
ll arr[maxNum];
ll sum[maxNum];

void update(ll idx, ll dif) {
	while (idx <= N) {
		sum[idx] += dif;
		idx += (idx & -idx);
	}
}

ll getSum(ll idx) {
	ll rnt = 0;
	while (idx > 0) {
		rnt += sum[idx];
		idx -= (idx & -idx);
	}
	return rnt;
}

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K >> M;
	for (ll i = 1; i <= N; i++) {
		cin >> arr[i];
		update(i, arr[i]);
	}

	for (ll i = 1; i <= K+M; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			ll dif = c - arr[b];
			update(b, dif);
			arr[b] = c;
		}
		else {
			cout << getSum(c) - getSum(b - 1) << '\n';
		}
	}



	return 0;
}