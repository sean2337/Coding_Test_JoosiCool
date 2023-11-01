#include<bits/stdc++.h>
using namespace std;

int xLen, yLen, len;
bool visited[10][10];
char arr[12][12];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int ans = 0;

void DFS(int y, int x, int count) {
	if (y == 0 && x == xLen - 1 && count == len) {
		ans++;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i]; int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= xLen || ny >= yLen|| visited[ny][nx]|| arr[ny][nx] == 'T') continue;
		visited[ny][nx] = 1;
		DFS(ny, nx, count + 1);
		visited[ny][nx] = 0;
	}
}


int main() {
	
	cin >> yLen >> xLen >> len;
	for (int i = 0; i < yLen; i++) {
		for (int j = 0; j < xLen; j++) {
			cin >> arr[i][j];
		}
	}
	visited[yLen - 1][0] = true;
	DFS(yLen - 1, 0, 1);
	cout << ans;

	return 0;
}