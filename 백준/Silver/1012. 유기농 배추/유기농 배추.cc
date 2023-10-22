#include<bits/stdc++.h>
using namespace std;

bool visited[53][53];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int T, xLen, yLen, inCount;
int x, y;

void DFS(int y, int x) {

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= xLen || ny < 0 || ny >= yLen || visited[ny][nx]) continue;
		visited[ny][nx] = 1;
		DFS(ny, nx);
	}

}

int main() {
	cin >> T;
	while (T--) {
		cin >> xLen >> yLen >> inCount;
		memset(visited, 1, sizeof(visited));
		while (inCount--)
		{
			cin >> x >> y;
			visited[y][x] = 0;
		}
		int result = 0;
		for (int i = 0; i <= yLen; i++) {
			for (int j = 0; j <= xLen; j++) {
				if (!visited[i][j]) {
					visited[i][j] = 1;
					result++;
					DFS(i, j);
				}
			}
		}
		cout << result << '\n';
	}

	return 0;
}