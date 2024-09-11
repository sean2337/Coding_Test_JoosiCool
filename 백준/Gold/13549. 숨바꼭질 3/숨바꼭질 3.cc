#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<tuple>
using namespace std;

const int maxN = 100004;
bool visited[maxN + 1];
int dx[] = { -1,1 };
queue<int>que;
int N, K, rnt;


void putNum(int num) {
	for (int i = num; i <= maxN; i*=2) {
		if (visited[i]) return;
		que.push(i);
		visited[i] = true;
	}
}


int main() {
	
	cin >> N >> K;

	putNum(N);
	while (que.size()) {
		int queSize = que.size();
		for (int i = 0; i < queSize; i++)
		{
			int num = que.front();
			que.pop();
			if (num == K) {
				cout << rnt;
				return 0;
			}

			for (int k = 0; k < 2; k++) {
				int next = num + dx[k];
				if (next < 0 || next > maxN || visited[next]) continue;
				putNum(next);
			}
		}
		rnt++;
	}

	return 0;
}