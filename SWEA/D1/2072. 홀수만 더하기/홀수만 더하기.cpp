#define _CRT_SECURE_NO_WARNINGS 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;
const ll maxSize = 1e8 + 4;
const ll INF = 987654321;
ll N, K, M, T, V, E, num, a, b, c, rnt, cnt;
string s;

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (ll t = 1; t <= T;t++) {
		rnt = 0;
		for (ll i = 0; i < 10; i++) {
			cin >> a;
			if (a % 2 == 1) rnt += a;
		}
		cout << "#" << t << " " << rnt<<'\n';
	}
	return 0;
}