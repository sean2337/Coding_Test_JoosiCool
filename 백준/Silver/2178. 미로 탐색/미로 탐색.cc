#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

int main() {
	
	const int maxX = 104;
	const int maxY = 104;

	int dx[4] = { 0, 0, 1, -1 };
	int dy[4] = { 1,-1,0,0 };
	int xLen, yLen;

	vector<string>coordVec;
	string input;

	// 좌표 만들기
	cin >> yLen >> xLen; 
	bool visit[maxX][maxY] = {false};
	for (int i = 0; i < yLen; i++) {
		cin >> input;
		coordVec.push_back(input);
	}
	
	
	// 큐 생성후 0,0에서 첫시작
	queue<pair<int,int>>queue;
	int curX, curY;
	int nextX, nextY;
	int count = 1;
	queue.push({ 0,0 });
	visit[0][0] = true;
	while (queue.size() != 0) {
		int queueSize = queue.size();
		count++;
		for (int i = 0; i < queueSize; i++) {
			curX = queue.front().first;
			curY = queue.front().second;
			queue.pop();


			for (int mIndex = 0; mIndex < 4; mIndex++) {
				nextX = curX + dx[mIndex];
				nextY = curY + dy[mIndex];
				if (nextX >= 0 && nextY >= 0 && nextX < xLen && nextY < yLen) {
					if (visit[nextX][nextY] != true && coordVec[nextY][nextX] == '1') {
						if (nextX == xLen - 1 && nextY == yLen - 1) {
							cout << count;
							return 0;
						}
						queue.push({ nextX,nextY });
						visit[nextX][nextY] = true;
					}
				}
			}


		}
	}
	return 0;
}