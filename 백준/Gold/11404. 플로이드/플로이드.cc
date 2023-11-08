#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long, long long>pairLong;
const ll INF = 987654321;
ll V, E, K, n, k, m;
ll dist[104][104];


int main() {

	fill(&dist[0][0], &dist[0][0] + 104 * 104, INF);

	cin >> V >> E;
	for (ll i = 0; i < E; i++) {
		cin >> n >> k >> m;
		n--; k--;
		dist[n][k] = min(dist[n][k], m);
	}

	for (ll k = 0; k < V; k++) {
		for (ll i = 0; i < V; i++) {
			for (ll j = 0; j < V; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	for (ll i = 0; i < V; i++) {
		for (ll j = 0; j < V; j++) {
			if (i == j || dist[i][j] == INF) cout << "0 ";
			else cout << dist[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}