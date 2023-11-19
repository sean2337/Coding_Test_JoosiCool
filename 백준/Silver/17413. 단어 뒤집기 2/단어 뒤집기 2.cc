#define _CRT_SECURE_NO_WARNINGS 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;
const ll maxSize = 1e8 + 4;
const ll INF = 987654321;
ll N, K, M, T, V, E, num, a, b, c;
string s;

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	getline(cin, s);

	ll l = 0, r = 0;
	for (ll i = 0; i < s.size(); i++) {
		if (s[i] == '<') {
			reverse(s.begin() + l, s.begin() + i);
			for (ll j = i + 1; j < s.size(); j++) {
				if (s[j] == '>') {
					i = j;
					l = j + 1;
					r = j;
					break;
				}
			}
		}
		else if (s[i] == ' ') {
			reverse(s.begin() + l, s.begin() + i);
			l = i + 1; r = i;
		}
		
	}
	reverse(s.begin() + l, s.end());
	cout << s;


	return 0;
}