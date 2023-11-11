#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;
const ll INF = 987654321;
ll N, K, T, a, b;
ll dist[404][404];
int main() {
	
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(&dist[0][0], &dist[0][0] + 404 * 404, INF);
	cin >> N >> K;
	for (int i = 1; i <= K; i++) {
		cin >> a >> b;
		a--; b--;
		dist[a][b] = 1;
	}

	for (ll k = 0; k < N; k++) {
		for (ll i = 0; i < N; i++) {
			for (ll j = 0; j < N; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	cin >> T;
	for (ll i = 0; i < T; i++) {
		cin >> a >> b;
		a--; b--;
		if (dist[a][b] != INF) {
			cout << -1 << '\n';
		}
		else if (dist[b][a] != INF) {
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}


	return 0;
}