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
	cin >> N;
	string s = "*";
	for (ll i = N - 1; i >= 0; i--) {
		for (ll j = 0; j < i; j++) {
			cout << " ";
		}
		cout << s <<'\n';
		s += "**";
	}
	s = s.substr(0, s.size() - 2);
	for (ll i =1; i < N; i++) {
		for (ll j = 0; j < i; j++) {
			cout << " ";
		}
		s = s.substr(0, s.size() - 2);
		cout << s << '\n';
	}

	
	return 0;
}