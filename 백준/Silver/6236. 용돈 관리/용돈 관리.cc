#include<bits/stdc++.h>
using namespace std;

int N, M;
const int maxN = 300004;
int arr[maxN];
int l = 1;
int r;

bool isPossible(int num) {
	int cnt = 1;
	int remainMoney = num;

	for (int i = 0; i < N; i++) {
		if (arr[i] > num) return false;
		if (remainMoney - arr[i] >= 0) {
			remainMoney -= arr[i];
		}
		else {
			remainMoney = num;
			remainMoney -= arr[i];
			cnt++;
			if (cnt > M) return false;
		}
	}
	return true;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		r += arr[i];
	}

	int minResult = numeric_limits<int>::max();

	while (l <= r) {
		int mid = (l + r) / 2;

		bool check = isPossible(mid);

		// 가능한 경우라면 
		if (check) {
			r = mid - 1;
			minResult = min(minResult, mid);
		}
		else {
			l = mid + 1;
		}
	}

	cout << minResult;

	return 0;
}