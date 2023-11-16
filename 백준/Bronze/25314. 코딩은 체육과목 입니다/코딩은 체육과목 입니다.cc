#define _CRT_SECURE_NO_WARNINGS 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;
map<char, ll>mp;
ll N;


int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	string s = "int";
	cin >> N;
	for (int i = 0; i < N; i += 4) {
		s = "long " + s;
	}
	cout << s;

	return 0;
}