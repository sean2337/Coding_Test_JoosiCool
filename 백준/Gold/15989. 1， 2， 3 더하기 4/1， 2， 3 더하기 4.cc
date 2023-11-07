#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[10004];
int N, n;

int main() {

	dp[0] = 1;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j < 10004; j++) {
			dp[j] += dp[j-i];
		}
	}
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n;
		cout << dp[n] << '\n';
	}

	
	return 0;
}