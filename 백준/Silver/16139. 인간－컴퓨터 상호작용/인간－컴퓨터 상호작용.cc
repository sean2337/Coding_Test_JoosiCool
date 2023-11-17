#define _CRT_SECURE_NO_WARNINGS 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;
using namespace std;
ll N, M, a, b, c, d;
ll sum[30][2004];

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	for (ll i = 1; i <= s.size(); i++) {
		char c = s[i-1];
		for (ll j = 0; j < 26; j++) {
			sum[j][i] = sum[j][i - 1];
		}
		sum[c - 'a'][i]++;
	}

	cin >> N;
	while (N--) {
		char c; ll a, b;
		cin >> c >> a >> b;
		b++;
		cout << sum[c - 'a'][b] - sum[c - 'a'][a] << '\n';
	}

	return 0;
}