#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include <algorithm>
#include<set>
#include <sstream>
#include <limits>
#include<math.h>
 using namespace std;

int arr[11][11];
int visit[11][11];

int dx[] = { -1,1,0,1 };
int dy[] = { 0,0,1,-1 };

int N;

void visitFlower(int x, int y) {
	visit[y][x] = true; visit[y+1][x] = true; visit[y-1][x] = true; visit[y][x+1] = true; visit[y][x-1] = true;
}

void noneVisitFlower(int x, int y) {
	visit[y][x] = false; visit[y + 1][x] = false; visit[y - 1][x] = false; visit[y][x + 1] = false; visit[y][x - 1] = false;
}

int minMoney = numeric_limits<int>::max();


void DFS(int x, int y, int count, int money) {

	if (count == 3) {
		minMoney = min(minMoney, money);
		return;
	}

	for (int nextX = 0; nextX < N; nextX++) {
		for (int nextY = 0; nextY < N; nextY++) {
			//범위를 벚어나면 패스
			if (nextX < 1 || nextY<1 || nextX >= N - 1 || nextY >= N - 1) continue;
			// 꽃모양 방문하지 않았을때
			if (!visit[nextY][nextX] && !visit[nextY + 1][nextX] && !visit[nextY][nextX + 1] && !visit[nextY - 1][nextX] && !visit[nextY][nextX - 1]) {
				int totalMoney = arr[nextY][nextX] + arr[nextY+1][nextX] + arr[nextY-1][nextX] + arr[nextY][nextX+1] + arr[nextY][nextX-1];
				visitFlower(nextX, nextY);
				DFS(nextX, nextY, count + 1, money + totalMoney);
				noneVisitFlower(nextX,nextY);
			}
		}
	}
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	visit[0][0] = true;
	DFS(0, 0, 0, 0);
	cout << minMoney;

	return 0;
}