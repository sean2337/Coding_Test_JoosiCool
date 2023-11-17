#define _CRT_SECURE_NO_WARNINGS 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;
using namespace std;
int N;
int num[1000];
int dp_left[1000], dp_right[1000];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> num[i];

	// dp 배열 모두 1 로 초기화 해주기
	fill_n(dp_left, 1000, 1);
	fill_n(dp_right, 1000, 1);

	for (int i = 0; i < N; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if ((num[j] < num[i]) && (dp_left[i] < dp_left[j] + 1)) dp_left[i] = dp_left[j] + 1;
		}
	}
	for (int i = N - 1; i >= 0; i--) {
		for (int j = i + 1; j < N; j++) {
			if ((num[j] < num[i]) && (dp_right[i] < dp_right[j] + 1)) dp_right[i] = dp_right[j] + 1;
		}
	}
	int m = 0;
	for (int i = 0; i < N; i++) {
		m = max(m, (dp_left[i] + dp_right[i]));
	}
	cout << m - 1 << endl;

	return 0;
}