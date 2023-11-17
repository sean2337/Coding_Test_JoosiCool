#define _CRT_SECURE_NO_WARNINGS 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;
ll N, M, rnt, cnt;
vector<ll>vec;
set<string>st;
stack<ll>stk;
string s, k;


int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for (ll i = 0; i < N; i++) {
		cin >> M;
		vec.push_back(M);
	}

	ll idx = 1;
	ll i = 0;
	for (ll idx = 1; idx <= N; idx++) {
		if (stk.size() && stk.top() == idx) {
			stk.pop();
		}
		else {
			if (i >= N) {
				cout << "Sad"; return 0;
			}
			if (vec[i] != idx) {
				idx--;
				stk.push(vec[i]);
			}
			i++;
		}
	}
	if (stk.empty()) {
		cout << "Nice";
	}
	else {
		cout << "Sad";
	}

	return 0;
}