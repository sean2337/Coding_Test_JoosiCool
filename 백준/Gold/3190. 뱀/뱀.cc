#include<bits/stdc++.h>
using namespace std;
#define time ff
typedef long long ll;
typedef pair<int, int> pairInt;

int N, appleCount, moveCount,num, x ,y;
char dir;
int visited[104][104];
int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };
deque<pairInt> snakeQue;
deque<pairInt>vec;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> appleCount;
	for (int i = 0; i < appleCount; i++) {
		cin >> y >> x;
		//2면 사과가 있는것
		visited[y - 1][x - 1] = 2;
	}
	cin >> moveCount;
	for (int i = 0; i < moveCount; i++) {
		cin >> num >> dir;
		if (dir == 'D') {
			vec.push_back({ num,1 });
		}
		else {
			vec.push_back({ num,3 });
		}
	}

	snakeQue.push_back({ 0,0 });
	int time = 0;
	int direction = 1;

	while (snakeQue.size()) {
		time++;
		int ny = snakeQue.front().first + dy[direction];
		int nx = snakeQue.front().second + dx[direction];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited[ny][nx] == 1) break;
		//사과 없는 곳이라면
		if (visited[ny][nx] == 0) {
			visited[snakeQue.back().first][snakeQue.back().second] = 0;
			snakeQue.pop_back();
		}
		snakeQue.push_front({ ny,nx });
		visited[ny][nx] = 1;
		if ( vec.size() && time == vec.front().first) {
			//방향은 이전꺼로 하고
			direction = (direction + vec.front().second) % 4;
			vec.pop_front();
		}
	}
	cout << time;

	return 0;
}