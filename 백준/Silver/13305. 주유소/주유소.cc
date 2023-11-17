#define _CRT_SECURE_NO_WARNINGS 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;
using namespace std;
ll N, M, K, a, b, c, d, rnt, cnt;
ll dis[100005];
ll arr[100005];


int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for (ll i = 0; i < N - 1; i++) {
		cin >> arr[i];
	}
	for (ll i = 0; i < N; i++) {
		cin >> dis[i];
	}
	priority_queue<ll, vector<ll>, greater<ll>> que;
	for (ll i = 0; i < N - 1; i++) {
		que.push(dis[i]);
		rnt += (arr[i] * que.top());
	}

	cout << rnt;

	return 0;
}