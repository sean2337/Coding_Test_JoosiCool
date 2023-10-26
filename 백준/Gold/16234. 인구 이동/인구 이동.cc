#include<iostream>
#include<vector>
#include<queue>
#include<cstdlib>
#include<string>
using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int arr[53][53] = { {0} };
bool visit[53][53] = { {false} };

int N ,L, R;
int sum;


//방문 처리 및 합계 구하기
void dfs(int y, int x, vector<pair<int, int>>&vec) {

	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];

		if (nextX >= 0 && nextX < N&& nextY >= 0 && nextY < N) {
			int minus = abs(arr[nextY][nextX] - arr[y][x]);
			if (!visit[nextY][nextX] && minus >=L && minus<=R) {
				visit[nextY][nextX] = true;
				sum += arr[nextY][nextX];
				vec.push_back({ nextY,nextX });
				dfs(nextY, nextX, vec);
			}
		}
	}
}

int main() {

	//입력 값 받아주기
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	int count = 0;
	vector<pair<int, int>> vec;
	while (true) {
		bool flag = false;
		fill(&visit[0][0], &visit[0][0] + 53 * 53, 0);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visit[i][j]) {
					vec.clear();
					sum = arr[i][j];
					visit[i][j] = 1;
					vec.push_back({ i,j });
					dfs(i, j, vec);
					if (vec.size() != 1) {
						flag = true;
						for(int vecIndex =0;vecIndex<vec.size();vecIndex++){
							pair<int, int> value = vec[vecIndex];
							arr[value.first][value.second] = sum / vec.size();
						}
					}
				}
			}
		}
		if (!flag) {
			cout << count << '\n';
			break;
		}
		else {
			count++;
		}
	}

	return 0;
}