#define _CRT_SECURE_NO_WARNINGS 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pairll;
const ll max_Size = 200004;
const ll INF = 987654321;
ll dis[404][403];
ll V, E, a, b, c;


int main() {
	
	fill(&dis[0][0], &dis[0][0] + 403 * 403, INF);
	cin >> V >> E;
	for (ll i = 0; i < E; i++) {
		cin >> a >> b >> c;
		a--; b--;
		dis[a][b] = min(dis[a][b], c);
	}

	for (ll k = 0; k < V; k++) {
		for (ll i = 0; i < V; i++) {
			for (ll j = 0; j < V; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	ll result = INF;
	for (ll i = 0; i < V; i++) {
		for (ll j = 0; j < V; j++) {
			if (i == j) continue;
			result = min(result, dis[i][j] + dis[j][i]);
		}
	}
	if (result == INF) {
		cout << -1;
		return 0;
	}
	cout << result;

	return 0;
}