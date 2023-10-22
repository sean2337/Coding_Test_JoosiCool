#include<bits/stdc++.h>
using namespace std;


int yLen, xLen;
int x, y;
int visited[103][103];


int main() {
	cin >> yLen >> xLen;
	char c;
	queue<pair<int, int>>que;
	memset(visited, -1, sizeof(visited));
	for (int i = 0; i < yLen; i++) {
		for (int j = 0; j < xLen; j++) {
			cin >> c;
			if (c == 'c') {
				que.push({ i,j });
				visited[i][j] = 0;
			}
		}
	}

	while (!que.empty()) {
		int queSize = que.size();
		for (int i = 0; i < queSize; i++) {
			tie(y, x) = que.front();
			que.pop();

			int nx = x + 1;
			int ny = y;

			if (nx >= xLen || visited[ny][nx] !=-1) continue;
			visited[ny][nx] = visited[y][x] + 1;
			que.push({ ny,nx });
		}
	}

	
	for (int i = 0; i < yLen; i++) {
		for (int j = 0; j < xLen; j++) {
			cout << visited[i][j] << " ";
		}
		cout << '\n';
	}
	
	return 0;
};