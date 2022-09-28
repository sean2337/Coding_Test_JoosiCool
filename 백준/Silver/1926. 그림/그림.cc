#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int board[501][501];
bool visit[501][501];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0, 1, 0,-1 };



int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<pair<int, int>>Q;

	
	int row, column;
	cin >> row >> column;

	for (int i{ 0 }; i < row; i++) {
		for (int j{ 0 }; j < column; j++) {
			cin >> board[i][j];
		}
	}

	
	int max{0};
	int outCount{ 0 };
	
	
	for (int i{ 0 }; i < row; i++) {
		for (int j{ 0 }; j < column; j++) {

			if (visit[i][j] != 0)
				continue;
			if (board[i][j] == 0)
				continue;
			int count{ 0 };

			visit[i][j] = 1;
			count++;
			outCount++;
			Q.push({ i, j });
			while (!Q.empty())
			{
				pair<int, int>cur = Q.front();
				Q.pop();
				

				for (int i{ 0 }; i < 4; i++) {
					int nx = cur.first + dx[i];
					int ny = cur.second + dy[i];
					
					if (nx < 0 || nx >= row || ny < 0 || ny >= column)
						continue;
					if (visit[nx][ny] || board[nx][ny] != 1)
						continue;


					visit[nx][ny] = 1;
					Q.push({ nx,ny });
					count++;

				}
				
					
			}

			if (max < count)
				max = count;

		}
	}

	cout << outCount << "\n" << max;



}