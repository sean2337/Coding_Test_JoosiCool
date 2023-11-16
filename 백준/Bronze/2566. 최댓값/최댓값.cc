#define _CRT_SECURE_NO_WARNINGS 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;
map<char, ll>mp;
ll N, M;
ll arr[12][12];
ll a, b, c;

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	ll maxNum = 0;
	ll y, x;
	for (ll i = 1; i <= 9; i++) {
		for (ll j = 1; j <= 9; j++) {
			cin >> N;
			if (maxNum <= N) {
				y = i; x = j;
				maxNum = N;
			}
		}
	}

	cout << maxNum << '\n' << y << " " << x;
	
	return 0;
}