#define _CRT_SECURE_NO_WARNINGS 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;
const ll INF = 987654321;
ll N, K, M, num, a, b, c;
string s;
vector<ll>vec;

ll dx[] = { 1,0,-1,0 };
ll dy[] = { 0,-1,0,1 };
ll xLen, yLen;
queue<pairll>que;
bool visited[1004][1004];
ll arr[1004][1004];

bool check() {
	for (ll i = 0; i < yLen; i++) {
		for (ll j = 0; j < xLen; j++) {
			if (arr[i][j] == 0) {
				return false;
			}
		}
	}
	return true;
}


ll BFS() {

	ll rnt = 0;
	while (que.size()) {
		if (check()) {
			return rnt;
		}
		ll queSize = que.size();
		rnt++;
		for (ll i = 0; i < queSize; i++) {
			ll y = que.front().first;
			ll x = que.front().second;
			que.pop();
			for (ll k = 0; k < 4; k++) {
				ll nx = x + dx[k];
				ll ny = y + dy[k];

				if (ny < 0 || nx < 0 || ny >= yLen || nx >= xLen || visited[ny][nx] || arr[ny][nx] != 0) continue;

				visited[ny][nx] = 1;
				arr[ny][nx] = 1;
				que.push({ ny,nx });
			}
		}
	}
	return -1;
}


int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> xLen >> yLen;
	for (ll i = 0; i < yLen; i++) {
		for (ll j = 0; j < xLen; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)
			{
				que.push({ i,j });
				visited[i][j] = 1;
			}
		}
	}
	cout << BFS();


	return 0;
}