#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;
typedef tuple<ll, ll, bool>TI;
ll V, E, K, u, v, w;
vector<pair<ll, ll>>adj[4004];
ll dist[4004];
ll dist2[4004][2];
const ll INF = 987654321;

priority_queue<pairll, vector<pairll>, greater<pairll>> pq;
priority_queue<TI, vector<TI>, greater<TI>> wolfPq;


int main() {
	cin >> V >> E;
	fill(dist, dist + 4004, INF);
	fill(&dist2[0][0], &dist2[0][0] + 4004 * 2, INF);
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		u--; v--;
		adj[u].push_back({ w * 2,v });
		adj[v].push_back({ w * 2,u });
	}

	//여우 부분
	pq.push({ 0,0 });
	dist[0] = 0;
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
	//늑대부분
	wolfPq.push({ 0, 0 ,0 });
	dist2[0][0] = 0;
	while (wolfPq.size()) {
		ll here;
		ll here_dist;
		ll here_count;
		tie(here_dist, here, here_count) = wolfPq.top();
		wolfPq.pop();
		if (dist2[here][here_count] != here_dist) continue;
		for (pairll there : adj[here]) {
			ll _dist = there.first;
			ll _there = there.second;

			ll checkNum = !here_count ? _dist/2 : _dist * 2;

			if (dist2[_there][!here_count] > dist2[here][here_count] + checkNum) {
				dist2[_there][!here_count] = dist2[here][here_count] + checkNum;
				wolfPq.push(make_tuple(dist2[_there][!here_count], _there, !here_count));
			}
		}
	}

	ll cnt = 0;
	for (int i = 1; i < V; i++) {
		ll d = min(dist2[i][0], dist2[i][1]);
		if (d > dist[i]) cnt++;
	}
	cout << cnt;
	return 0;
}