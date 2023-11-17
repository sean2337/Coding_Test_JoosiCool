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
	
	cin >> N;
	for (ll i = 0; i < N; i++) {
		cin >> s >> k;
		if (k == "enter") {
			st.insert(s);
		}
		else {
			st.erase(s);
		}
	}
	vector<string> ss(st.begin(), st.end());
	sort(ss.begin(), ss.end());
	reverse(ss.begin(), ss.end());
	for (string s : ss) {
		cout << s << '\n';
	}


	return 0;
}