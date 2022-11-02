#include<iostream>
#include<vector>
using namespace std;



int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int input;
	cin >> input;

	vector<int>dp(1000001,0);

	dp[2] = 1;
	dp[3] = 1;


	for (int i{ 4 }; i <= input; i++)
	{


		dp[i] = dp[i - 1] + 1;

		if ((i % 3 == 0)&& (i % 2 == 0)) {
			dp[i] = min(1 + dp[i / 3], 1 + dp[i / 2]);
		}
		else if (i % 2 == 0) {
			dp[i] = min(1 + dp[i-1], 1+ dp[i / 2]);
		}
		else if (i % 3 == 0) {
			dp[i] = min(1 + dp[i - 1], 1+ dp[i / 3]);
		}

	}


	
	cout << dp[input];


	return 0;
}