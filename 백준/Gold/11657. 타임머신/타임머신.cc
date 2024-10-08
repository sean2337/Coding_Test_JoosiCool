#include<iostream>
#include<queue>
#include <utility>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pairll;
const ll maxN = 1e8 + 4;
const ll maxM = 504;
const ll INF = 1e18;

vector<pairll> adj[maxM];
ll dis[maxM];


ll N, M, a, b, c;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (ll i = 0; i < M; i++) {
		cin >> a >> b >> c;
		adj[a].push_back({ c,b });
	}

	fill(dis, dis + maxM, INF);
	dis[1] = 0;

	queue<ll>que;
	for (ll i = 0; i < N; i++) {
		for (ll here = 1; here <= N; here++) {
			for (pairll _there:adj[here]) {
				ll there = _there.second;
				ll there_dist = _there.first;
				if (dis[here] != INF && dis[there] > dis[here] + there_dist) {
					dis[there] = dis[here] + there_dist;
					if (i == N - 1) que.push(here);
				}
			}
		}
	}
	if (que.size()) {
		cout << -1;
		return 0;
	}

	for (ll i = 2; i <= N; i++) {
		if (dis[i] == INF) cout << -1 << "\n";
		else cout << dis[i] << "\n";
	}


	return 0;
}