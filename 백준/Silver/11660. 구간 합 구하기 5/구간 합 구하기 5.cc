#define _CRT_SECURE_NO_WARNINGS 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;
using namespace std;
ll N, M, a, b, c, d;
ll arr[1030][1030];
ll sum[1030][1030];

int main() {

	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (ll i = 1; i <= N; i++) {
		for (ll j = 1; j <= N; j++) {
			cin >> arr[i][j];
			sum[i][j] = arr[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
		
	}
	for (ll i = 1; i <= M; i++) {
		cin >> b >> a >> d >> c;

		cout << sum[d][c] - sum[d][a-1] - sum[b-1][c] + sum[b-1][a-1] << '\n';
	}

	return 0;
}