// 가중치가 다른데, 한 곳에서만 출발하는 경우
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;
const ll INF = 987654321;
ll dist[20004];
vector<pairll>adj[20004];
priority_queue<pairll, vector<pairll>, greater<pairll>> que;
ll N, M, a, b, c, K;


int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	for (ll i = 0; i < M; i++) {
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
	}

	fill(dist, dist + 20004, INF);

	dist[K] = 0;
	que.push({ 0,K });
	while (que.size()) {
		ll here_dist = que.top().first;
		ll here = que.top().second;
		que.pop();
		if (dist[here] != here_dist) continue;
		for (pairll there : adj[here]) {
			ll there_dist = there.second;
			ll _there = there.first;

			if (dist[here] + there_dist < dist[_there]) {
				dist[_there] = dist[here] + there_dist;
				que.push({ dist[_there], _there });
			}
		}
	}
	
	for (ll i = 1; i <= N; i++) {
		if (dist[i] == INF) {
			cout << "INF";
		}
		else cout << dist[i];
		cout << '\n';
	}


	return 0;
}