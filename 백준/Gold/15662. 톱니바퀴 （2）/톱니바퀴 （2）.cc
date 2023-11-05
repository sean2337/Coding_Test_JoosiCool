#include<bits/stdc++.h>
using namespace std;

bool visited[1004];
vector<string>wheelVec;
vector<pair<int, int>>rotateVec;
int N, T, idx, dir;
int dx[] = { -1,1 };

void go(int idx, int dir) {

	for (int i = 0; i < 2; i++) {
		int nIdx = idx + dx[i];
		if (nIdx < 0 || nIdx >= N || visited[nIdx]) continue;
		visited[nIdx] = 1;
		
		if (i == 0) {
			if (wheelVec[idx][6] != wheelVec[nIdx][2]) {
				if (dir == -1) go(nIdx, 1);
				else go(nIdx, -1);
			}
		}
		else {
			if (wheelVec[idx][2] != wheelVec[nIdx][6]) {
				if (dir == -1) go(nIdx, 1);
				else go(nIdx, -1);
			}
		}
	}
	rotateVec.push_back({ idx,dir });
}

void rotateWheel(int idx, int dir) {
	if (dir == -1) {
		rotate(wheelVec[idx].begin(), wheelVec[idx].begin() + 1, wheelVec[idx].end());
	}
	else {
		rotate(wheelVec[idx].begin(), wheelVec[idx].begin() + wheelVec[idx].size() - 1, wheelVec[idx].end());
	}
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	string in;
	for (int i = 0; i < N; i++) {
		cin >> in;
		wheelVec.push_back(in);
	}
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> idx >> dir; idx--;
		memset(visited, 0, sizeof(visited));
		visited[idx] = 1;
		go(idx, dir);
		for (auto i : rotateVec) {
			rotateWheel(i.first, i.second);
		}
		rotateVec.clear();
	}

	int rnt = 0;
	for (int i = 0; i < N; i++) {
		if (wheelVec[i][0] == '1') rnt++;
	}
	cout << rnt;

	return 0;
}
