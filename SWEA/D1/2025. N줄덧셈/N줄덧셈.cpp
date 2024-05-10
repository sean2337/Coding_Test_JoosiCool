#define _CRT_SECURE_NO_WARNINGS 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T;

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	ll rnt = 0;
	for (ll i = 1; i <= T; i++) {
		rnt += i;
	}
	cout << rnt;

	return 0;
};