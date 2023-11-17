#define _CRT_SECURE_NO_WARNINGS 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;
using namespace std;
ll N, M, K, a, b, c, d, rnt, cnt;
vector<ll>vec;

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll N, K;
	cin >> N >> K;
	for (ll i = 0; i < N; i++) {
		cin >> a;
		vec.push_back(a);
	}
	
	for (ll i = N - 1; i >= 0; i--) {
		if (K - vec[i] >= 0) {
			cnt += K / vec[i];
			K = K % vec[i];
		}
	}
	cout << cnt;

	return 0;
}