#include<bits/stdc++.h>
using namespace std;

int yLen, xLen;
int arr[53][53];
vector<pair<int, int>> landVec;
bool visited[53][53];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int BFS(int y, int x) {
	memset(visited, 0, sizeof(visited));
	queue<pair<int, int>> que;
	visited[y][x] = 1;
	que.push({ y,x });

	int result = 0;

	while (!que.empty()) {
		int queSize = que.size();
		for (int k = 0; k < queSize; k++) {
			int curX = que.front().second;
			int curY = que.front().first;
			que.pop();
			for (int i = 0; i < 4; i++) {
				int nx = curX + dx[i];
				int ny = curY + dy[i];
				if (nx < 0 || ny < 0 || nx >= xLen || ny >= yLen || visited[ny][nx]) continue;
				if (arr[ny][nx] == 1) {
					que.push({ ny,nx });
					visited[ny][nx] = 1;
				}
			}
		}
		result++;
	}
	return result-1;
}



int main() {

	char c;
	cin >> yLen >> xLen;
	for (int i = 0; i < yLen; i++) {
		for (int j = 0; j < xLen; j++) {
			cin >> c;
			if (c == 'L') {
				arr[i][j] = 1;
				landVec.push_back({ i,j });
			}
		}
	}

	int result = 0;
	for (pair<int, int> land : landVec) {
		result = max(result, BFS(land.first, land.second));
	}
	cout << result;

	return 0;
}