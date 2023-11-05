#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pairInt;
int prefixSumA[2004]; int arrA[1004];
int prefixSumB[2004]; int arrB[1004];
map<int, int>mapA, mapB;

int N, m, n;

void cal(int prefixSum[], int n, map<int,int>&mp) {
	for (int size = 1; size <= n; size++) {
		for (int start = size; start <= n + size - 1; start++) {
			int sum = prefixSum[start] - prefixSum[start - size];
			mp[sum]++;
			if (size == n) break;
		}
	}
	return;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> m >> n;
	for (int i = 1; i <= m; i++) {
		cin >> arrA[i];
		prefixSumA[i] = prefixSumA[i - 1] + arrA[i];
	}
	for (int i = m+1; i <= 2 * m; i++) {
		prefixSumA[i] = prefixSumA[i - 1] + arrA[i-m];
	}
	for (int i = 1; i <= n; i++) {
		cin >> arrB[i];
		prefixSumB[i] = prefixSumB[i - 1] + arrB[i];
	}
	for (int i = n+1; i <= 2 * n; i++) {
		prefixSumB[i] = prefixSumB[i - 1] + arrB[i - n];
	}

	cal(prefixSumA, m, mapA); cal(prefixSumB, n, mapB);



	int rnt = 0;
	rnt += mapA[N]; rnt += mapB[N];
	for (int i = 1; i < N; i++) {
		rnt += (mapA[i] * mapB[N - i]);
	}
	cout << rnt;
	return 0;
}
