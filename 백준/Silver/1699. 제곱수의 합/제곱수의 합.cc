#include<iostream>
#include<queue>
#include <utility>
using namespace std;

const int maxN = 100004;
int n;
int dp[maxN];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		dp[i] = i;
	}


	for (int i = 1; i <= n; i++) {
		for (int divNum = 1; divNum * divNum <= i; divNum++) {
			dp[i] = min(dp[i], dp[i - divNum * divNum] + 1);
		}

	}
	cout << dp[n];

	return 0;
}