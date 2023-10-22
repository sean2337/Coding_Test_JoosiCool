#include<bits/stdc++.h>
using namespace std;

vector<int>vec[53];
int T, num, eraseNum;


int DFS(int parent) {
	int cnt = 0;
	for (int i = 0; i < vec[parent].size(); i++) {
		int child = vec[parent][i];
		if (child == eraseNum) continue;
		cnt += DFS(child);
	}
	if (cnt == 0) return 1;
	return cnt;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> T;
	int first;
	for (int i = 0; i < T; i++) {
		cin >> num;
		if (num == -1) { 
			first = i;
			continue; 
		}
		vec[num].push_back(i);
	}
	cin >> eraseNum;
	if (eraseNum == first) {
		cout << 0;
		return 0;
	}
	cout << DFS(first);
	
	
	
	return 0;
};