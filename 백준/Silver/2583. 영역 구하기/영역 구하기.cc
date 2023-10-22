#include<bits/stdc++.h>
using namespace std;

bool visited[103][103];
int arr[103][103];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int xLen, yLen, T;
int result;
int resultCount = 0;


void DFS(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= xLen || ny < 0 || ny >= yLen || visited[ny][nx]) continue;
		visited[ny][nx] = 1;
		result++;
		DFS(ny, nx);
	}

}


int main() {

	cin >> yLen >> xLen >> T;
	int x1, x2, y1, y2;
	vector<int>vec;
	while (T--) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1; i < y2; i++) {
			for (int j = x1; j < x2; j++) {
				visited[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < yLen; i++) {
		for (int j = 0; j < xLen; j++) {
			if (!visited[i][j]) {
				result = 1;
				visited[i][j] = 1;
				resultCount++;
				DFS(i, j);
				vec.push_back(result);
			}
		}
	}

	sort(vec.begin(), vec.end());
	cout << resultCount << '\n';
	for (int v : vec) cout << v << " ";


	return 0;
}