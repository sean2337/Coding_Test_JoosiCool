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
	cin >> M;
	while (M--) {
		string s;
		cin >> s;
		cout << s[0] << s[s.size() - 1] << '\n';

	}
	
	return 0;
}