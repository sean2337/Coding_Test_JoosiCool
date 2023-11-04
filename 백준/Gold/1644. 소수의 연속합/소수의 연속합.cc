#include<bits/stdc++.h>
using namespace std;

int N;
vector<int>numVec;
bool primeNum[4000003];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	vector<bool>primeNum(N + 1, true);
	vector<int>prime;
	for (int p = 2; p*p <=N; p++) {
		if (primeNum[p]) {
			for (int i = p * p; i <= N; i += p) {
				primeNum[i] = false;
			}
		}
	}

	for (int i = 2; i <= N; i++) {
		if (primeNum[i]) prime.push_back(i);
	}

	int l = 0, r = 0, sum = 0, cnt = 0;
	while (true) {
		if (sum >= N) {
			sum -= prime[l]; l++;
		}
		else if (r == prime.size()) break;
		else {
			sum += prime[r]; r++;
		}
		if (sum == N) cnt++;

	}
	cout << cnt;
	return 0;
}