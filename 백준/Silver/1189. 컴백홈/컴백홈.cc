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



 char arr[6][6];
 int visit[6][6];
 int yLen, xLen, goalDistance;
 int dx[] = { -1,1,0,0 };
 int dy[] = { 0,0,1,-1 };
 int result = 0;

 void DFS(int x, int y, int distance) {
	 if ( y == 0 && x == xLen-1) {
		 if (distance == goalDistance) {
			 result++;
		 }
		 return;
	 }

	 for (int i = 0; i < 4; i++) {
		 int nX = x + dx[i];
		 int nY = y + dy[i];

		 if (nX >= xLen || nY >= yLen || nX < 0 || nY < 0) continue;
		 if (!visit[nY][nX] && arr[nY][nX]=='.') {
			 visit[nY][nX] = true;
			 DFS(nX, nY, distance + 1);
			 visit[nY][nX] = false;
		 }
	 }
 }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> yLen >> xLen >> goalDistance;
	for (int i = 0; i < yLen; i++) {
		for (int j = 0; j < xLen; j++) {
			cin >> arr[i][j];
		}
	}
	
	visit[yLen - 1][0] = true;
	DFS(0, yLen - 1, 1);
	cout << result;

	return 0;
}