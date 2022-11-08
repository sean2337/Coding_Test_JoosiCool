#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<map>
#include<cstring>
using namespace std;

//bfs 방문 했는지 체크하는 배열
bool check[51][51];
//bfs에 모든 방향 체크하기 위하 배열
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
//배추를 심었는지 체크하는 배열
int a[51][51];

// 문제에서 주어진 m: 가로길이 n: 세로길이 k: 배추 개수
int m, n, k;


void dfs(int x, int y) {
	//방문 했다고 표시
	check[x][y] = true;
	for (int i{ 0 }; i < 4; i++)
	{
		//x,y 기준으로 모든 방향 체크
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < n && ny>=0 && ny < m) {
			//배추가 있고, 방문하지 않았다면, 탐색 계속 실행
			if (a[nx][ny] == 1) {
				if (!check[nx][ny]) {
					dfs(nx, ny);
				}
			}
		}
		else
			continue;
	}
}


int main() {
	
	int count;
	int X, Y;
	cin >> count;
	while (count--) {
		int result{ 0 };
		cin >> m >> n >> k;

		while (k--) {
			cin >> X >> Y;
			a[Y][X] = 1;
		}

		for (int i{ 0 }; i < n; i++) {
			for (int j{ 0 }; j < m; j++) {

				if (check[i][j] == 0 && a[i][j] == 1)
				{
					dfs(i, j);
					result++;
				}
					

			}
		}

		cout << result << "\n";
		memset(check, false, sizeof(check));
		memset(a, 0, sizeof(a));

	}




	return 0;
}