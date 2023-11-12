#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;
const ll INF = 987654322;
ll N, M, T, F, s, g, h;
ll a, b, c;
ll dist[2004];


int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	while (T--) {
		fill(dist, dist + 2004, INF);
		vector< pairll>adj[2004];
		cin >> N >> M >> F;
		cin >> s >> g >> h;

		for (ll i = 0; i < M; i++) {
			cin >> a >> b >> c;
			c = c * 2;
			if (a == g && b == h) {
				c--;
			}
			else if (a == h && b == g) c--;

			adj[a].push_back({ b,c });
			adj[b].push_back({ a,c });
		}

		vector<int>vec;
		for (int i = 0; i < F; i++) {
			cin >> a;
			vec.push_back(a);
		}
		sort(vec.begin(), vec.end());

		priority_queue<pairll, vector<pairll>, greater<pairll>> que;
		dist[s] = 0;
		que.push({ 0,s });
		while (que.size()) {
			ll here = que.top().second;
			ll here_dist = que.top().first;
			que.pop();
			if (dist[here] != here_dist) continue;
			for (pairll there : adj[here]) {
				ll _there = there.first;
				ll there_dist = there.second;
				if (dist[_there] > dist[here] + there_dist) {
					dist[_there] = dist[here] + there_dist;
					que.push({ dist[_there],_there });
				}
			}
		}
		vector<ll>result;
		for (ll i = 0; i < vec.size(); i++) {
			if (dist[vec[i]] % 2 == 1) {
				cout << vec[i] << " ";
			}
		}
		cout << '\n';
	}

	return 0;
}