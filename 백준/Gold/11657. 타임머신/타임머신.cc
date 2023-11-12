// 가중치가 다른데, 한 곳에서만 출발하는 경우
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;
const ll INF = 987654321;
ll dist[504];
vector<pairll> adj[504];
ll N, M, a, b, c;

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(dist, dist + 504, INF);

	cin >> N >> M;
	for (ll i = 0; i < M; i++) {
		cin >> a >> b >> c;
		a--; b--;
		adj[a].push_back({ b,c });
	}
	dist[0] = 0;
	queue<ll>que;
	for (ll i = 0; i < N; i++) {
		for (ll here = 0; here < N; here++) {
			for (pairll there : adj[here]) {
				ll there_dist = there.second;
				ll _there = there.first;

				if (dist[here] !=INF && dist[_there] > dist[here] + there_dist) {
					dist[_there] = dist[here] + there_dist;
					if (i == N - 1) que.push(here);
				}

			}
		}
	}

	if (que.size()) {
		cout << -1;
		return 0;
	}
	for (ll i = 1; i < N; i++) {
		if (dist[i] == INF) {
			cout << -1 << '\n';
		}
		else {
			cout << dist[i] << '\n';
		}
	}
	return 0;
}
