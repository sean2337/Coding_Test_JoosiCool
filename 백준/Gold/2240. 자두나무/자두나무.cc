#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int T, W;
int arr[1004];
//0: 몇초, 1: 이동 횟수, 2: 현재 위치한 곳
int dp[1004][34][2];

int go(int idx, bool tree, int cnt) {
	if (cnt < 0) return -1;
	if (idx == T) return cnt == 0 ? 0 : -1;
	int& ret = dp[idx][tree][cnt];
	// 값이 있다면 리턴
	if (ret >= 0) return ret;
	return ret = max(go(idx + 1, !tree, cnt - 1), go(idx + 1, tree, cnt)) + (tree == arr[idx] - 1);
}


int main() {

	cin >> T >> W;
	for (int i = 0; i < T; i++) {
		cin >> arr[i];
	}

	memset(dp, -1, sizeof(dp));
	cout << max(go(0, 1, W - 1), go(0, 0, W)) << '\n';

	return 0;
}