#define _CRT_SECURE_NO_WARNINGS 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;
const ll maxSize = 1e8 + 4;
const ll INF = 987654321;
ll N, K, M, T, V, E, num, a, b, c, rnt, cnt;
string s;

ll monthDayArr[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

bool possibleFun(string month,string day) {
	ll m = stoll(month);
	ll d = stoll(day);
	if (m < 1 || m>12)return false;
	if (monthDayArr[m] < d) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (ll t = 1; t <= T;t++) {
		cin >> s;
		string year = s.substr(0, 4);
		string month =  s.substr(4, 2);
		string day = s.substr(6);

		if (possibleFun(month, day)) {
			cout << "#" << t << " " << year<<"/"<<month<<'/'<<day<< '\n';
		}
		else {
			cout << "#" << t << " "<< -1 << '\n';
		}

	}
	return 0;
}