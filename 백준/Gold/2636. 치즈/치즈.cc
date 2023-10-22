#include<bits/stdc++.h>
using namespace std;


int arr[103][103];
int yLen, xLen;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0, };
bool visited[103][103];

void DFS(int y, int x, vector<pair<int, int>>& vec) {

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || ny >= yLen || nx >= xLen || visited[ny][nx]) continue;
		visited[ny][nx] = 1;

		if (arr[ny][nx] == 1) {
			vec.push_back({ ny,nx });
		}
		else {
			DFS(ny, nx, vec);
		}

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
	int before = 0;
	while (true) {
		vector<pair<int, int>> vec;
		memset(visited, 0, sizeof(visited));
		visited[0][0] = 1;
		DFS(0, 0, vec);
		if (vec.size() == 0) {
			break;
		}

		result++;

		before = vec.size();
		for (int i = 0; i < vec.size(); i++) {
			int x, y;
			tie(y, x) = vec[i];
			arr[y][x] = 0;
		}

	}
	cout << result <<"\n"<< before;
	return 0;
};