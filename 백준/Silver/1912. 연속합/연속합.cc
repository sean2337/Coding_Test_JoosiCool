#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N , num;
ll currentSum = 0;
ll maxSum = numeric_limits <ll> ::min();

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> num;
		currentSum = max((ll)num, currentSum + num);
		maxSum = max(maxSum, currentSum);
	}
	maxSum = max(maxSum, currentSum);
	cout << maxSum;

	return 0;
}
