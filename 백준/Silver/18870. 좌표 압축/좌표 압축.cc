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
		vec2.push_back(M);
	}

	vector<ll>vec1(st.begin(), st.end());
	sort(vec1.begin(), vec1.end());

	for (ll num : vec2) {
		auto pos = lower_bound(vec1.begin(), vec1.end(), num);
		ll idx = (ll)(pos - vec1.begin());
		cout << idx << " ";
	}

	return 0;
}