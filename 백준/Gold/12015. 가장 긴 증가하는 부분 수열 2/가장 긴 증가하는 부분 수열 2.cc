#define _CRT_SECURE_NO_WARNINGS 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;
using namespace std;
const ll INF = 987654321;
ll N, M, K, a, b, c, d, rnt, cnt, num;
ll dis[1000004];
ll len;

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	fill(dis, dis + 1000004, INF);
	for (ll i = 0; i < N; i++) {
		cin >> num;
		auto pos = lower_bound(dis, dis + len, num);
		if (*pos == INF) len++;
		*pos = num;
	}

	cout << len;

	return 0;
}