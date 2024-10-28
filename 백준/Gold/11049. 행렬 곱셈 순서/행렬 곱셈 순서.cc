#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int maxN = 504;
int dp[maxN][maxN], arr[maxN][maxN];
int N, a, b;
const int INF = 987654321;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}


	// i는 개수
	for (int i = 1; i <= N; i++) {
		// j는 가능 시작점
		for (int j = 0; j + i < N; j++) {
			dp[j][i+j] = INF;
			// k는 중간치
			for (int k = j; k <= i + j; k++) {
				dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + arr[j][0] * arr[k][1] * arr[i+j][1]);
			}
		}
	}

	cout << dp[0][N - 1];

	return 0;
}