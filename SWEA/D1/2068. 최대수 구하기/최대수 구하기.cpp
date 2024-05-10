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

	cin >> T;
	for (ll i = 1; i <= T; i++) {
		ll maxRnt = 0;
		for (ll j = 0; j < 10; j++) {
			cin >> a;
			maxRnt = max(a, maxRnt);
		}
		cout << "#" << i <<" "<<maxRnt<<'\n';
	}

	return 0;
};