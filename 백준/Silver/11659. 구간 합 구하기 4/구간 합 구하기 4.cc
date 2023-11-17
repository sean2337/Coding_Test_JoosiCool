#define _CRT_SECURE_NO_WARNINGS 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;
using namespace std;
ll N, M, a, b;
ll arr[100004];
ll sum[100004];

int main() {

	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (ll i = 1; i <= N; i++) {
		cin >> arr[i];
		sum[i] = arr[i] + sum[i - 1];
	}
	for (ll i = 1; i <= M; i++) {
		cin >> a >> b;
		cout << sum[b] - sum[a - 1] << '\n';
	}


	return 0;
}