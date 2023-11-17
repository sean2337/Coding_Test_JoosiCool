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
ll arr[200][200];
ll cnt1, cnt2;


ll go(ll s, ll y, ll x) {
	ll check = arr[y][x];
	for (ll i = y; i < y+s; i++) {
		for (ll j = x; j < x+s; j++) {
			if (arr[i][j] != check) {
				ll ds = s / 2;
				return go(ds, y, x) + go(ds, y+ds, x) + go(ds, y, x+ds) + go(ds, y+ds, x+ds);
			}
		}
	}
	if (check) cnt1++;
	else cnt2++;
	return check;
}


int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	
	go(N, 0, 0);
	cout << cnt2 << '\n' << cnt1;

	return 0;
}