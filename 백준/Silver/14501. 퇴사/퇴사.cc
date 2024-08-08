#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;


const ll maxSize = 2004;
ll dp[maxSize];
pairll arr[maxSize];
ll N,T,P;

int main() {
	cin >> N;
	ll maxValue = 0;
	for (ll i = 0; i < N; i++) {
		cin >> T >> P;
		arr[i] = { T,P };
	}
	for (ll i = 0; i <= N; i++) {
		dp[i] = max(dp[i], maxValue);

		T = arr[i].first;
		P = arr[i].second;
		dp[i + T] = max(dp[i + T] , dp[i] + P);
		maxValue = max(maxValue, dp[i]);
	}
	cout << dp[N];
	
	return 0;
}