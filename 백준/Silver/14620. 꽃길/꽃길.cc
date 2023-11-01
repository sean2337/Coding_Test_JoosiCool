#include<bits/stdc++.h>
using namespace std;

int N;
bool visited[12][12];
int arr[12][12];
int x1, x2, x3, yv1, y2, y3;
int dx[] = { 0,-1,1,0,0 };
int dy[] = { 0, 0,0,-1,1 };

bool blockCheck(int x, int y) {
	if (x <= 0 || y <= 0 || x + 1>= N || y + 1 >= N) return false;
	return true;
}

int checkFlower(int y, int x) {
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (visited[ny][nx]) return -1;
		visited[ny][nx] = 1;
		sum += arr[ny][nx];
	}
	return sum;
}

int main() {
	int result = 987654321;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N*N; i++) {
		for (int j = 0; j < i; j++) {
			for (int k = 0; k < j; k++) {
				x1 = i % N; yv1 = i / N;
				x2 = j % N; y2 = j / N;
				x3 = k % N; y3 = k / N;
				//벽 걸리는지 체크
				if (!blockCheck(x1, yv1) || !blockCheck(x2, y2) || !blockCheck(x3, y3))continue;
				memset(visited, 0, sizeof(visited));
				int sum1 = checkFlower(yv1, x1); int sum2 = checkFlower(y2, x2); int sum3 = checkFlower(y3, x3);
				if (sum1 == -1 || sum2 == -1 || sum3 == -1) continue;
				result = min(result, sum1 + sum2 + sum3);
			}
		}
	}

	cout << result;

	return 0;
}