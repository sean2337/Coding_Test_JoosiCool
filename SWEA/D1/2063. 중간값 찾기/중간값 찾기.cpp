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
	vector<ll>vec;
	cin >> T;
	for (ll i = 0; i < T; i++) {
		cin >> a;
		vec.push_back(a);
	}

	sort(vec.begin(), vec.end());
	cout << vec[T / 2];

	return 0;
};