#define _CRT_SECURE_NO_WARNINGS 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;
const ll INF = 987654321;
ll N, K, M, num, a, b, c;
const ll maxSize = 30;

ll visited[maxSize][maxSize];
ll arr[maxSize][maxSize];
ll dx[] = { 1,0,-1,0 };
ll dy[] = { 0,-1,0,1 };
vector<ll> vec;
ll cnt = 0;


void DFS(ll y, ll x) {
	for (ll i = 0; i < 4; i++)
	{
		ll nx = x + dx[i];
		ll ny = y + dy[i];
		if (ny<0 || ny>=N || nx < 0 || nx >= N||visited[ny][nx]) continue;
		if (arr[ny][nx] != 1) continue;
		visited[ny][nx] = 1;
		cnt++;
		DFS(ny, nx);
	}
}


int main() {

	cin >> N;
	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < N; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < N; j++) {
			if (arr[i][j] == 1 && !visited[i][j]) {
				cnt = 1;
				visited[i][j] = true;
				DFS(i, j);
				vec.push_back(cnt);
			}
		}
	}
	cout << vec.size() << '\n';
	sort(vec.begin(), vec.end());
	for (ll i : vec) {
		cout << i << " ";
	}


	return 0;
}