#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;


const ll maxV = 20004;
const ll INF = 1e18;
ll dis[maxV];
vector<pairll> adj[maxV];
priority_queue<pairll, vector<pairll>, greater<pairll>> que;

ll V, E, K, a, b, c;


int main() {
	
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E >> K;
	for (ll i = 0; i < E; i++) {
		cin >> a >> b >> c;
		adj[a].push_back({ c,b });
	}

	fill(dis, dis + maxV, INF);
	dis[K] = 0;
	que.push({ 0,K });

	while (que.size()) {
		ll here = que.top().second;
		ll here_dist = que.top().first;
		que.pop();

		if (dis[here] != here_dist) continue;

		for (pairll _there : adj[here]) {
			ll there = _there.second;
			ll there_dist = _there.first;

			if (dis[there] > dis[here] + there_dist) {
				dis[there] = dis[here] + there_dist;
				que.push({ dis[there], there });
			}
		}
	}

	for (ll i = 1; i <= V; i++) {
		cout << (dis[i] == INF ? "INF" : to_string(dis[i])) << '\n';
	}

	return 0;
}