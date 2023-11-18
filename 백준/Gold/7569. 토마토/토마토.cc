#define _CRT_SECURE_NO_WARNINGS 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;
const ll INF = 987654321;
ll N, K, M, num, a, b, c;
string s;
vector<ll>vec;

struct P {
	int x, y, z;
};

ll dx[] = { 1,0,-1,0 ,0,0 };
ll dy[] = { 0,-1,0,1 ,0,0 };
ll dz[] = { 0, 0 , 0 , 0 , 1, -1 };
ll xLen, yLen, zLen;
queue<P>que;
bool visited[104][104][104];
ll arr[104][104][104];

bool check() {
	for (ll i = 0; i < yLen; i++) {
		for (ll j = 0; j < xLen; j++) {
			for (ll z = 0; z < zLen; z++) {
				if (arr[i][j][z] == 0) {
					return false;
				}
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
			ll y = que.front().y;
			ll x = que.front().x;
			ll z = que.front().z;
			que.pop();
			for (ll k = 0; k < 6; k++) {
				ll nx = x + dx[k];
				ll ny = y + dy[k];
				ll nz = z + dz[k];

				if (ny < 0 || nx < 0 || ny >= yLen || nx >= xLen || nz<0||nz>=zLen|| visited[ny][nx][nz] || arr[ny][nx][nz] != 0) continue;

				visited[ny][nx][nz] = 1;
				arr[ny][nx][nz] = 1;
				P plus;
				plus.x = nx; plus.y = ny; plus.z = nz;
				que.push(plus);
			}
		}
	}
	return -1;
}


int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> xLen >> yLen >> zLen;
	for (ll h = 0; h < zLen; h++) {
		for (ll i = 0; i < yLen; i++) {
			for (ll j = 0; j < xLen; j++) {
				cin >> arr[i][j][h];
				if (arr[i][j][h] == 1)
				{
					P plus;
					plus.x = j; plus.y = i; plus.z = h;
					que.push(plus);
					visited[i][j][h] = 1;
				}
			}
		}
	}
	
	cout << BFS();


	return 0;
}