#define _CRT_SECURE_NO_WARNINGS 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;
const ll maxSize = 1e8 + 4;
const ll INF = 987654321;
ll N, K, M, T, V, E, num, a, b, c, rnt;
string s;

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b;
	if (a == 1) {
		if (b == 2) {
			cout << 'B';
		}
		else {
			cout << 'A';
		}
	}
	else if (a == 2) {
		if (b == 1) {
			cout << 'A';
		}
		else {
			cout << 'B';
		}
	}
	else {
		if (b == 2) {
			cout << 'A';
		}
		else {
			cout << 'B';
		}
	}

	return 0;
};