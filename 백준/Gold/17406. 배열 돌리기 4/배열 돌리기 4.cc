#include<bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int arr[54][54];
int extraArr[54][54];
int visited[54][54];
int yLen, xLen, rotateInCount;
int a, b, c, minRst = INF;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int dir = 0;
int sx, sy, ex, ey;

struct A {
	int l, r, cnt;
};

vector<A> rotateVec;
vector<int>idxVec;
vector<pair<int, int>> moveVec;

void go(int y, int x, int first) {
	if (!first && y == sy && x == sx) dir++;
	if (!first && y == ey && x == sx) dir++;
	if (!first && y == sy && x == ex) dir++;
	if (!first && y == ey && x == ex) dir++;

	int ny = y + dy[dir]; int nx = x + dx[dir];
	if (visited[ny][nx])return;
	visited[ny][nx] = 1;
	moveVec.push_back({ ny,nx });
	go(ny, nx, 0);
}

void rotateAll(int y, int x, int cnt) {
	for (int i = 1; i <= cnt; i++) {
		sy = y - 1 * i; sx = x - 1 * i;
		ey = y + 1 * i; ex = x + 1 * i;
		dir = 0;
		moveVec.clear();
		memset(visited, 0, sizeof(visited));
		visited[sy][sx] = 1;
		moveVec.push_back({ sy,sx });
		//움직일꺼를 여기에 담아둠.
		go(sy, sx, 1);
		vector<int> chageVec;
		for (pair<int,int> c : moveVec)chageVec.push_back(extraArr[c.first][c.second]);
		rotate(chageVec.begin(), chageVec.begin() + moveVec.size() - 1, chageVec.end());
		for (int i = 0; i < moveVec.size(); i++) {
			extraArr[moveVec[i].first][moveVec[i].second] = chageVec[i];
		}
	}

}

//값을 돌리고 최솟값을 리턴함.
int solve() {
	for (int i = 0; i < idxVec.size(); i++) {
		rotateAll(rotateVec[idxVec[i]].l, rotateVec[idxVec[i]].r, rotateVec[idxVec[i]].cnt);
	}

	int ret = INF;
	for (int i = 0; i < yLen; i++) {
		int cnt = 0;
		for (int j = 0; j < xLen; j++) {
			cnt += extraArr[i][j];
		}
		ret = min(ret, cnt);
	}
	return ret;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> yLen >> xLen >> rotateInCount;
	for (int i = 0; i < yLen; i++) {
		for (int j = 0; j < xLen; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < rotateInCount; i++) {
		cin >> a >> b >> c;
		a--; b--;
		rotateVec.push_back({ a,b,c });
		idxVec.push_back(i);
	}


	do{
		//2차원 배열 초기화
		memcpy(extraArr, arr, sizeof(extraArr));
		minRst = min(minRst, solve());
	} while (next_permutation(idxVec.begin(), idxVec.end()));

	cout << minRst;


	return 0;
}
