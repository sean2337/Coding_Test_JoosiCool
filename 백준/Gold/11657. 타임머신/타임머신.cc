#define _CRT_SECURE_NO_WARNINGS 
#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;
const ll INF = 987654321;
ll N, K, M, num, a, b, c;
ll dis[504];
vector<pairll> adj[504];


int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(&dis[0], &dis[0] + 504, INF);
	cin >> N >> M;
	for (ll i = 0; i < M; i++) {
		cin >> a >> b >> c;
		a--; b--;
		adj[a].push_back({ c,b });
	}

	dis[0] = 0;
	queue<ll>que;

	for (ll i = 0; i < N; i++) {
		for (ll here = 0; here < N; here++) {
			for (pairll _there : adj[here]) {
				ll there = _there.second; ll there_dist = _there.first;
				if ( dis[here] != INF && dis[there] > dis[here] + there_dist) {
					dis[there] = dis[here] + there_dist;
					if (i == N - 1)que.push(here);
				}
			}
		}
	}
	if (que.size()) {
		cout << -1; return 0;
	}
	for (ll i = 1; i < N; i++) {
		if (dis[i] == INF) {
			cout << -1 << '\n';
		}
		else cout << dis[i] << '\n';
	}

	return 0;
}