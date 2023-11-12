// 가중치가 다른데, 한 곳에서만 출발하는 경우
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;
const ll INF = 987654321;
ll N, M, K, a, b, c;
ll dist[1004];
ll dist2[1004];
vector<pairll>adj[1004];
vector<pairll>adj2[1004];


int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	priority_queue< pairll, vector<pairll>, greater<pairll>>que;

	fill(dist, dist + 1004, INF);
	fill(dist2, dist2 + 1004, INF);

	cin >> N >> M >> K;
	for (ll i = 0; i < M; i++) {
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj2[b].push_back({ a,c });
	}


	dist[K] = 0;
	que.push({ 0,K });
	while (que.size()) {
		ll here = que.top().second;
		ll _dist = que.top().first;
		que.pop();
		if (dist[here] != _dist) continue;
		for (pairll there : adj[here]) {
			ll _there = there.first;
			ll there_dist = there.second;

			if (dist[_there] > dist[here] + there_dist) {
				dist[_there] = dist[here] + there_dist;
				que.push({ dist[_there],_there });
			}
		}
	}


	dist2[K] = 0;
	que.push({ 0,K });
	while (que.size()) {
		ll here = que.top().second;
		ll _dist = que.top().first;
		que.pop();
		if (dist2[here] != _dist) continue;
		for (pairll there : adj2[here]) {
			ll _there = there.first;
			ll there_dist = there.second;

			if (dist2[_there] > dist2[here] + there_dist) {
				dist2[_there] = dist2[here] + there_dist;
				que.push({ dist2[_there],_there });
			}
		}
	}
	ll rnt = 0;
	for (ll i = 1; i <= N; i++) {
		rnt = max(rnt, dist[i] + dist2[i]);
	}
	cout << rnt;

	return 0;
}