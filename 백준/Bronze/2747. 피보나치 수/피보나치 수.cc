#define _CRT_SECURE_NO_WARNINGS 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;
const ll maxSize = 1e8 + 4;
const ll INF = 987654321;
ll N, K, M, T, num, a, b, c;
ll dp[50];

ll fibo(ll idx) {
	if (idx == 1 || idx == 0)return idx;
	if (dp[idx]) return dp[idx];
	return dp[idx] = fibo(idx - 1) + fibo(idx - 2);
}




int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	cout << fibo(N);


	return 0;
}