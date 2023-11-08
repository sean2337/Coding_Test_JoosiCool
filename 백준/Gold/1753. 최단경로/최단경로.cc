#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;
ll V, E, K, u, v, w;
vector<pair<ll, ll>>adj[20001];
ll dist[20001];
const ll INF = 987654321;
priority_queue<pairll, vector<pairll>, greater<pairll>> pq;

int main() {
	cin >> V >> E >> K;
	fill(dist, dist + 20001, INF);

	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		adj[u].push_back({ w,v });
	}

	pq.push({ 0,K });
	dist[K] = 0;
	while (pq.size()) {
		ll here = pq.top().second;
		ll here_dist = pq.top().first;
		pq.pop();
		if (dist[here] != here_dist) continue;
		for (pairll there : adj[here]) {
			ll _dist = there.first;
			ll _there = there.second;
			if (dist[_there] > dist[here] + _dist) {
				dist[_there] = dist[here] + _dist;
				pq.push({ dist[_there], _there });
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) cout << "INF" << '\n';
		else cout << dist[i] << '\n';
	}
	return 0;
}

