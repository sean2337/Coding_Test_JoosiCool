#define _CRT_SECURE_NO_WARNINGS 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;
map<char, ll>mp;
ll a, b, c, d, e, f;


int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b >> c >> d >> e >> f;
	ll x = (e * c - b * f) / (a * e - b * d);
	ll y = (a * f - c * d) / (a * e - b * d);;
	cout << x << " " << y;


	return 0;
}