#include<bits/stdc++.h>
using namespace std;

int yLen, xLen;
int x, y, fx, fy;
bool visited[1003][1003];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };


int BFS(int y, int x, queue<pair<int,int>>fireQue) {
	
	queue<pair<int, int>>que;
	visited[y][x] = 1;
	que.push({ y,x });

	int result = 0;

	while (que.size()) {
		result++;

		int fireSize = fireQue.size();
		for (int k = 0; k < fireSize; k++) {
			tie(fy, fx) = fireQue.front(); fireQue.pop();
			for (int i = 0; i < 4; i++) {
				int nfy = fy + dy[i];
				int nfx = fx + dx[i];

				if (nfy < 0 || nfx < 0 || nfy >= yLen || nfx >= xLen||visited[nfy][nfx]) continue;
				visited[nfy][nfx] = 1;
				fireQue.push({ nfy,nfx });
			}
		}

		int queSize = que.size();
		for (int k = 0; k < queSize; k++) {
			tie(y, x) = que.front(); que.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny < 0 || nx < 0 || ny >= yLen || nx >= xLen) return result;
				if (visited[ny][nx]) continue;
				visited[ny][nx] = 1;
				que.push({ ny,nx });
			}
		}
	}

	return -1;
}



int main() {

	cin >> yLen >> xLen;
	int jX, jY;
	char c;
	queue<pair<int, int>>fireQue;
	for (int i = 0; i < yLen; i++)
	{
		for (int j = 0; j < xLen; j++) {
			cin >> c;
			if (c == 'J') {
				jY = i;
				jX = j;
			}
			else if (c == 'F') {
				visited[i][j] = 1;
				fireQue.push({ i,j });
			}
			else if (c == '#') {
				visited[i][j] = 1;
			}
		}
	}

	int result = BFS(jY, jX, fireQue);
	if (result == -1) {
		cout << "IMPOSSIBLE";
	}else {
		cout << result;
	}
	

	return 0;
}