#define _CRT_SECURE_NO_WARNINGS 
#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;
const ll INF = 987654321;
ll N, M, R, num, a, b, c;
vector<ll> adj[100004];
ll arr[100004];
bool visited[100004];
ll cnt = 0;

void DFS(ll idx) {
	cnt++;
	arr[idx] = cnt;
	for (ll next : adj[idx]) {
		if (visited[next])continue;
		visited[next] = 1;
		DFS(next);
	}
}


int main() {

	cin >> N >> M >> R;
	for (ll i = 0; i < M; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (ll i = 1; i <= N; i++) {
		sort(adj[i].begin(), adj[i].end());
	}

	visited[R] = 1;
	DFS(R);

	for (ll i = 1; i <= N; i++) {
		cout << arr[i] << '\n';
	}

	return 0;
}