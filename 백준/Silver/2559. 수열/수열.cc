#include<iostream>
#include<string>
#include<vector>
#include<array>
#include <limits>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

int arr[100003];
long long sum[100003];
int main() {

	int T, N;
	cin >> T >> N;
	for (int i = 1; i <= T; i++) {
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}

	long long maxResult = numeric_limits<long long>::min();

	for (int i = 0; i + N <= T; i++) {
		maxResult = max(maxResult, sum[i + N] - sum[i]);
	}

	cout << maxResult;

	return 0;
}