#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairLong;
const ll INF = 987654321;
ll N, M, a, b, c;
vector<pairLong>adj[504];
ll dist[504];


int main() {
	cin >> N >> M;
	for (ll i = 0; i < M; i++) {
		cin >> a >> b >> c;
		a--; b--;
		adj[a].push_back({ b, c });
	}
	fill(dist, dist + 504, INF);
	dist[0] = 0;
	queue<ll>que;
	for (int i = 0; i < N; i++) {
		for (int here = 0; here < N; here++) {
			for (pairLong there : adj[here]) {
				ll _dist = there.second;
				ll _there = there.first;
				if (dist[here] != INF && dist[here] + _dist < dist[_there]) {
					dist[_there] = dist[here] + _dist;
					if (i == N - 1)que.push(i);
				}
			}
		}
	}

	if (que.size()) {
		cout << -1; return 0;
	}
	for (int i = 1; i < N; i++) {
		if (dist[i] == INF) cout << -1;
		else cout << dist[i];
		cout << endl;
	}


	return 0;
}