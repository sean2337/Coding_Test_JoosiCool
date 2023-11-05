#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int yLen, xLen, num;
int arr[13][13];
bool visited[13][13];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
struct A {
	int y, x, kind;
};

vector<A>cameraVec;
vector<vector<int>>dirVec;

void getDirVec(vector<int>vec) {
	if (vec.size() == cameraVec.size()) {
		dirVec.push_back(vec);
		return;
	}
	for (int i = 0; i < 4; i++) {
		vec.push_back(i);
		getDirVec(vec);
		vec.pop_back();
	}
}

void go(int y, int x, int dir) {
	int nx = x + dx[dir]; int ny = y + dy[dir];
	if (arr[ny][nx] == 6) return;
	if (ny < 0 || nx < 0 || nx >= xLen || ny >= yLen) return;
	visited[ny][nx] = 1;
	go(ny, nx, dir);
}

int getVisited() {
	int cnt = 0;
	for (int i = 0; i < yLen; i++) {
		for (int j = 0; j < xLen; j++) {
			if (!visited[i][j] && arr[i][j] != 6) cnt++;
		}
	}
	return cnt;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> yLen >> xLen;
	for (int i = 0; i < yLen; i++) {
		for (int j = 0; j < xLen; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 0 && arr[i][j] != 6) {
				cameraVec.push_back({ i,j,arr[i][j] });
			}
		}
	}
	vector<int>vec;
	getDirVec(vec);
	int minResult = yLen * xLen;
	for (vector<int> vec : dirVec) {
		int result = 0;
		memset(visited, 0, sizeof(visited));
		
		for (int i = 0; i < vec.size(); i++) {
			int dir = vec[i];
			int y = cameraVec[i].y; int x = cameraVec[i].x; 
			int kind = cameraVec[i].kind;
			visited[y][x] = 1;
			if (kind >= 1) go(y, x, dir);
			if (kind >= 2 && kind !=3) go(y, x, (dir+2) % 4);
			if (kind >= 3) go(y, x, (dir + 3) % 4);
			if(kind>=5) go(y, x, (dir + 3) % 1);
		}
		minResult = min(minResult, getVisited());
	}
	cout << minResult;

	return 0;
}
