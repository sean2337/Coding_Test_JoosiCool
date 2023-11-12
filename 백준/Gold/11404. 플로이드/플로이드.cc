// 가중치가 다른데, 한 곳에서만 출발하는 경우
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;
const ll INF = 987654321;
ll dist[104][104];
ll N, M, a, b, c;

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(&dist[0][0], &dist[0][0] + 104 * 104, INF);

	cin >> N >> M;
	for (ll i = 0; i < M; i++) {
		cin >> a >> b >> c;
		a--; b--;
		dist[a][b] = min(dist[a][b],c);
	}

	for (ll k = 0; k < N; k++) {
		for (ll i = 0; i < N; i++) {
			for (ll j = 0; j < N; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < N; j++) {
			if (i == j || dist[i][j] == INF) cout << 0 << " ";
			else cout << dist[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}