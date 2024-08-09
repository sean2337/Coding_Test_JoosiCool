#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair < ll, ll>pairll;

const ll maxN = 1300;


ll arr[maxN][maxN];
ll N;

ll solution(ll y, ll x, ll len) {
	if (len == 1) {
		return arr[y][x];
	}

	//두번째꺼 찾기
	if (len == 2) {
		vector<ll>vec = { arr[y][x],arr[y + 1][x],arr[y][x + 1],arr[y + 1][x + 1] };
		sort(vec.begin(), vec.end());
		return vec[1];
	}

	vector<ll> vec = { solution(y, x, len / 2), solution(y + len/2 , x, len / 2) , solution(y, x + len/2, len / 2) ,solution(y + len / 2, x + len / 2, len / 2) };
	sort(vec.begin(), vec.end());
	return vec[1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0);

	cin >> N;

	for (ll y = 0; y < N; y++) {
		for (ll x = 0; x < N; x++) {
			cin >> arr[y][x];
		}
	}
	cout << solution(0, 0, N);
	
	return 0;
}