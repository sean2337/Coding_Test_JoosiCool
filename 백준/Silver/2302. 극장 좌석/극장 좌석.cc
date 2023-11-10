#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairLong;
const ll INF = 987654321;
ll dp[44];
ll N, M, num;
vector<ll>vec;


int main() {

	dp[0] = 1;
	dp[1] = 1;
	cin >> N >> M;
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	ll result = 1;
	ll before = 0;
	for (ll i = 0; i < M; i++) {
		cin >> num;
		result *= dp[num - 1 - before];
		before = num;
	}
	result *= dp[N - before];
	cout << result;

	return 0;
}