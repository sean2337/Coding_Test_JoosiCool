#include<bits/stdc++.h>
using namespace std;

int cArr[6][3] = { {1,3,9},{1,9,3},{3,1,9},{3,9,1},{9,1,3},{9,3,1} };
int visited[63][63][63];

int x, y, z;

struct mutal {
	int a = 0;
	int b = 0;
	int c = 0;
};

int BFS(mutal first) {
	queue<mutal>que;
	que.push(first);
	visited[first.a][first.b][first.c] = 1;
	
	int result = 0;
	while (que.size()) {
		result++;
		int queSize = que.size();
		for (int k = 0; k < queSize; k++) {
			x = que.front().a;
			y = que.front().b;
			z = que.front().c;
			que.pop();

			for (int i = 0; i < 6; i++) {
				int nx = x - cArr[i][0];
				int ny = y - cArr[i][1];
				int nz = z - cArr[i][2];

				if (nx <= 0 && ny <= 0 && nz <= 0) {
					return result;
				}
				if (nx < 0) nx = 0;
				if (ny < 0) ny = 0;
				if (nz < 0) nz = 0;

				if (visited[nx][ny][nz]) continue;
				visited[nx][ny][nz] = 1;
				mutal newMutal;
				newMutal.a = nx; newMutal.b = ny; newMutal.c = nz;
				que.push(newMutal);
			}
		}
	}
	return -1;
}


int main() {

	int N, i;
	vector<int>vec;
	cin >> N;
	while (N--) {
		cin >> i;
		vec.push_back(i);
	}
	mutal newMutal;
	if (vec.size() >=1) {
		newMutal.a = vec[0];
	}
	if (vec.size() >= 2) {
		newMutal.b = vec[1];
	}
	if (vec.size() >= 3) {
		newMutal.c = vec[2];
	}
	cout << BFS(newMutal);

	return 0;
}