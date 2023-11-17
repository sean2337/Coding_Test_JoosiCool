#define _CRT_SECURE_NO_WARNINGS 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;
ll N, M;
vector<ll>vec2;
set<ll>st;


int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for (ll i = 0; i < N; i++) {
		cin >> M;
		st.insert(M);
	}
	cin >> N;
	for (ll i = 0; i < N; i++) {
		cin >> M;
		if (st.find(M) == st.end()) {
			cout << 0;
		}
		else {
			cout << 1;
		}
		cout << " ";
	}
	return 0;
}