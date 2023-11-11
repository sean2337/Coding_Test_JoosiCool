#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;
const ll INF = 987654321;
vector<pairll>adj[54];
ll dist[54];
ll money[54];
ll visited[54];
ll N, M, s, e, a, b, c, ok;
int main() {
	
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> s >> e >> M;
	for (ll i = 0; i < M; i++) {
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
	}

	for (ll i = 0; i < N; i++) {
		cin >> money[i];
	}

	fill(dist, dist + 54, INF);
	dist[s] = -money[s];
	queue <ll>que;
	for (ll i = 0; i < N; i++) {
		for (ll here = 0; here < N; here++) {
			for (pairll there : adj[here]) {
				ll _dist = there.second;
				ll _there = there.first;
				if (dist[here] != INF && dist[here] + _dist - money[_there] < dist[_there]) {
					dist[_there] = dist[here] + _dist - money[_there];
					if (i == N - 1) que.push(here);
				}
			}
		}
	}
	while (que.size()) {
		int here = que.front(); que.pop();
		for (pair<int, int> there : adj[here]) {
			if (there.first == e) {
				ok = 1; break;
			}
			if (!visited[there.first]) {
				visited[there.first] = 1;
				que.push(there.first);
			}
		}
		if (ok) break;
	}
	
	if (dist[e] == INF) {
		cout << "gg";
	}
	else if (ok) {
		cout << "Gee";
	}
	else {
		cout << - dist[e];
	}

	return 0;
}