#define _CRT_SECURE_NO_WARNINGS 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;
const ll INF = 987654321;
ll N, M, R, num, a, b, c;
vector<ll> adj[100004];
ll arr[100004];
bool visited[100004];
ll cnt = 0;

bool compare(ll a, ll b) {
	return a > b;
}

void BFS(ll idx) {
	cnt++;
	arr[idx] = cnt;
	queue<ll>que;
	que.push(idx);

	while (que.size()) {
		ll queSize = que.size();
		for (ll i = 0; i < queSize; i++) {
			ll here = que.front(); que.pop();
			for (ll next : adj[here]) {
				if (visited[next]) continue;
				cnt++;
				visited[next] = 1;
				arr[next] = cnt;
				que.push(next);
			}
		}
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
		sort(adj[i].begin(), adj[i].end(),compare);
	}

	visited[R] = 1;
	BFS(R);

	for (ll i = 1; i <= N; i++) {
		cout << arr[i] << '\n';
	}

	return 0;
}