#define _CRT_SECURE_NO_WARNINGS 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pairll;
const ll max_Size = 104;

ll T, N, M, K, a, b;
bool visited[max_Size][max_Size];
ll arr[max_Size][max_Size];
ll dx[] = { 1,0,-1,0 };
ll dy[] = { 0,1,0,-1 };
ll cnt;
vector<ll>vec;

void DFS(ll y, ll x) {
	for (ll i = 0; i < 4; i++) {
		ll ny = y + dy[i];
		ll nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx]) continue;
		if (arr[ny][nx] == 0) continue;
		visited[ny][nx] = 1;
		cnt++;
		DFS(ny, nx);
	}
}




int main() {
	
		ll rnt = 0;
		cin >> N ;
		for (ll i = 0; i < N; i++) {
			for (ll j = 0; j < N; j++) {
				scanf("%1d", &arr[i][j]);
			}
		}

		for (ll i = 0; i < N; i++) {
			for (ll j = 0; j < N; j++) {
				if (arr[i][j] == 1 && !visited[i][j]) {
					rnt++;
					cnt = 1;
					visited[i][j] = 1;
					DFS(i, j);
					vec.push_back(cnt);
				}
			}
		}
		sort(vec.begin(), vec.end());
		cout << rnt << '\n';
		for (ll i : vec) {
			cout << i << "\n";
		}



	return 0;
}