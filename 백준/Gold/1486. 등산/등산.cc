#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long, long long>pairLong;
const ll INF = 987654321;

ll N, M, T, D;
ll height[30][30];
ll times[3000][3000];
string s;
vector<ll>vec;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,-1,1 };

int main() {

	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> T >> D;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < M; j++) {
			if (s[j] >= 'A' && s[j] <= 'Z') {
				height[i][j] = (ll)(s[j] - 'A');
			}
			else {
				height[i][j] = (ll)(s[j] - 'a') + 26;
			}
		}
	}

	//갈수있는곳 벡터에 넣기
	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < M; j++) {
			vec.push_back(i * 100 + j);
		}
	}
	fill(&times[0][0], &times[0][0] + 3000 * 3000, INF);

	//하나씩 보면서 그 다음으로 이동할때 걸리는 시간 times에 넣고 있음.
	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < M; j++) {
			ll x = j; ll y = i;
			for (ll k = 0; k < 4; k++) {
				ll ny = y + dy[k]; ll nx = x + dx[k];
				if (ny < 0 || nx<0 || ny >= N || nx>=M) continue;
				ll dif = abs(height[ny][nx] - height[y][x]);
				if (dif <= T) {
					if (height[ny][nx] > height[y][x]) {
						times[y * 100 + x][ny * 100 + nx] = dif * dif;
					}
					else {
						times[y * 100 + x][ny * 100 + nx] = 1;
					}
				}
			}
		}
	}

	for (int k : vec) {
		for (int i : vec) {
			for (int j : vec) {
				times[i][j] = min(times[i][j], times[i][k] + times[k][j]);
			}
		}
	}
	ll rnt = height[0][0];
	for (int i : vec) {
		if (times[0][i] + times[i][0] <= D) {
			rnt = max(rnt, height[i/100][i%100]);
		}
	}
	cout << rnt;

	return 0;
}