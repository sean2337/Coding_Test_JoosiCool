#include<iostream>
#include<vector>
using namespace std;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

bool visit[30];
char arr[21][21];
int result = 0;
int yLen, xLen;

void DFS(int x, int y, int count) {

	result = max(result, count);

	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];

		if (nextX < 0 || nextY < 0 || nextX >= xLen || nextY >= yLen) continue;
		//방문하지 않고 이전에 봤던 값이 아니라면?
		int nextValue = (int)arr[nextY][nextX] - 'A';
		if (!visit[nextValue]) {
			visit[nextValue] = true;
			DFS(nextX, nextY, count + 1);
			visit[nextValue] = false;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> yLen >> xLen;

	for (int i = 0; i < yLen; i++) {
		for (int j = 0; j < xLen; j++) {
			cin >> arr[i][j];
		}
	}

	int firstValue = (int)arr[0][0] - 'A';
	visit[firstValue] = true;
	DFS(0, 0, 1);

	cout << result;


	return 0;
}