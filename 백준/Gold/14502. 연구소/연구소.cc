#include<bits/stdc++.h>
using namespace std;


int arr[10][10];
int copyArr[10][10];
bool visited[10][10];

void copyFun() {
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			copyArr[i][j] = arr[i][j];
		}
	}
}

int yLen, xLen;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0, };

void virusDFS(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= xLen || ny >= yLen || visited[ny][nx] || copyArr[ny][nx] == 1) continue;
		copyArr[ny][nx] = 2;
		visited[ny][nx] = 1;
		virusDFS(ny, nx);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> yLen >> xLen;
	for (int i = 0; i < yLen; i++) {
		for (int j = 0; j < xLen; j++) {
			cin >> arr[i][j];
		}
	}

	int result = 0;

	for (int i = 0; i < xLen * yLen; i++) {
		for (int j = i + 1; j < xLen * yLen; j++) {
			for (int k = j + 1; k < xLen * yLen; k++) {
				if (arr[i / xLen][i % xLen] || arr[j / xLen][j % xLen] || arr[k / xLen][k % xLen])continue;
				copyFun();
				memset(visited, 0, sizeof(visited));
				// 벽 세우기
				copyArr[i / xLen][i % xLen] = 1;
				copyArr[j / xLen][j % xLen] = 1;
				copyArr[k / xLen][k % xLen] = 1;

				// 바이러스 퍼지게 하기
				for (int y = 0; y < yLen; y++) {
					for (int x = 0; x < xLen; x++) {
						if (copyArr[y][x] == 2 && !visited[y][x]) {
							visited[y][x] = 1;
							virusDFS(y, x);
						}
					}
				}
				//안전 구역 계산하기
				int cnt = 0;
				for (int y = 0; y < yLen; y++) {
					for (int x = 0; x < xLen; x++) {
						if (copyArr[y][x] == 0) {
							cnt++;
						}
					}
				}
				result = max(cnt, result);
			}
		}
	}

	cout << result;


	return 0;
};