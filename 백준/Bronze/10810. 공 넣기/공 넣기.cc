#define _CRT_SECURE_NO_WARNINGS 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;
map<char, ll>mp;
ll N, M;
ll arr[104];
ll a, b, c;

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	for (ll i = 0; i < M; i++) {
		cin >> a >> b >> c;
		for (ll i = a; i <= b; i++) {
			arr[i] = c;
		}
	}
	for (ll i = 1; i <= N; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}