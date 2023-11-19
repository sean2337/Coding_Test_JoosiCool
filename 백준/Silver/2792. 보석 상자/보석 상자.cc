#define _CRT_SECURE_NO_WARNINGS 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;
const ll maxSize = 1e8 + 4;
const ll INF = 987654321;
ll N, K, M, T, num, a, b, c;
ll arr[300004];
ll rnt = INF;

bool check(ll mid) {
	ll cnt = 0;
	for (ll i = 0; i < M; i++) {
		cnt += arr[i] / mid;
		if (arr[i] % mid)cnt++;
	}

	return cnt<=N;
}


int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (ll i = 0; i < M; i++) {
		cin >> arr[i];
	}

	ll l = 1, r = INF, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			rnt = min(rnt, mid);
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << rnt;

	return 0;
}