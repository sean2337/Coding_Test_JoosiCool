#define _CRT_SECURE_NO_WARNINGS 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;
ll N, M, rnt, cnt;
vector<ll>vec2;
set<string>st;
string s;


int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	for (ll i = 0; i < N; i++) {
		cin >> s;
		st.insert(s);
	}
	for (ll i = 0; i < M; i++) {
		cin >> s;
		if (st.find(s) != st.end())rnt++;
	}
	cout << rnt;

	return 0;
}