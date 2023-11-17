#define _CRT_SECURE_NO_WARNINGS 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;
ll N, M, rnt, cnt;
vector<string>vec;
set<string>st;
string s, k;


int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> s;
	for (ll i = 1; i <= s.size(); i++) {
		for (ll j = 0; j + i <= s.size(); j++) {
			st.insert(s.substr(j, i));
		}
	}

	cout << st.size();


	return 0;
}