#define _CRT_SECURE_NO_WARNINGS 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;
ll arr[200][200];
ll cnt1, cnt2, N, M;
set<string>st;




int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	vector<ll>vec;
	for (ll i = 0; i < N; i++) {
		vec.push_back(i + 1);
	}

	do {
		string s = "";
		for (ll i = 0; i < M; i++) {
			s += to_string(vec[i]);
			sort(s.begin(), s.end());
		}
		st.insert(s);
	} while (next_permutation(vec.begin(), vec.end()));

	for (string s : st) {
		for (char c : s) {
			cout << c << " ";
		}
		cout << '\n';
	}

	return 0;
}