#include<iostream>
#include<vector>
#include<cstring>
#include <cstdlib> 
using namespace std;

const int maxN = 24;
int arr[maxN];

int N, S;
int cnt;

void go(int n, int sum) {
	if (n >= N) {
		if (sum == S) cnt++;
		return;
	}
	go(n + 1, sum);
	go(n + 1, sum + arr[n]);
}


int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	vector<int> vec;
	go(0, 0);
	if (S == 0) cnt--;
	cout << cnt;

	return 0;
}