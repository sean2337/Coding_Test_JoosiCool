#include<bits/stdc++.h>
using namespace std;

bool visited[103][103];
int arr[103][103];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int len, T;

void DFS(int y, int x) {
	for (int i = 0; i < 4; i++) {

		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= T || ny < 0 || ny >= T || visited[ny][nx]) continue;
		if (arr[ny][nx] > len) {
			visited[ny][nx] = 1;
			DFS(ny, nx);
		}
	}
}


int main() {
	int result;
	int maxResult = 0;
	int maxNum = 0;

	cin >> T;
	for (int i = 0; i < T; i++) {
		for (int j = 0; j < T; j++) {
			cin >> arr[i][j];
			maxNum = max(maxNum, arr[i][j]);
		}
	}
	for (len = 0; len <= maxNum; len++) {
		memset(visited, 0, sizeof(visited));
		result = 0;
		for (int i = 0; i < T; i++) {
			for (int j = 0; j < T; j++) {
				if (len < arr[i][j] && !visited[i][j]) {
					visited[i][j] = 1;
					DFS(i, j);
					result++;
				}
			}
		}
		maxResult = max(maxResult, result);
	}
	cout << maxResult;
	

	return 0;
}