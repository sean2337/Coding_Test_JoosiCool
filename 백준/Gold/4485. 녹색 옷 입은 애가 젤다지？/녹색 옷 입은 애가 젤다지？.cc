#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;
ll T, N, K;
ll dist[130][130];
ll arr[130][130];
const ll INF = 987654321;
ll dx[] = { -1,1,0,0 };
ll dy[] = { 0,0,1,-1 };

struct Cood {
	ll dis, y, x;
};

struct comp {
	bool operator()(Cood a, Cood b) {
		return a.dis > b.dis;
	}
};

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
	ll cnt = 1;
	while (true) {
		cin >> N;
		if (N == 0)break;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}

		fill(&dist[0][0], &dist[0][0] + 130 * 130, INF);
		dist[0][0] = arr[0][0];
		priority_queue<Cood, vector<Cood>, comp>que;
		que.push({ arr[0][0],0,0});

		while (que.size()) {
			ll here_dis = que.top().dis;
			ll here_y = que.top().y; ll here_x = que.top().x;
			que.pop();
			if (dist[here_y][here_x] != here_dis) continue;

			for (ll i = 0; i < 4; i++) {
				ll there_x = here_x + dx[i];
				ll there_y = here_y + dy[i];
				if (there_x < 0 || there_y < 0 || there_x >= N || there_y >= N) continue;
				ll there_dist = arr[there_y][there_x];

				if (dist[there_y][there_x] > dist[here_y][here_x] + there_dist) {
					dist[there_y][there_x] = dist[here_y][here_x] + there_dist;
					que.push({ dist[there_y][there_x], there_y, there_x });
				}
			}
		}

		cout << "Problem " << cnt << ": " << dist[N - 1][N - 1] << '\n';
		cnt++;
	}

	return 0;
}