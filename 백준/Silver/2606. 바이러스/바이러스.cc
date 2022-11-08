#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<map>
#include<cstring>
using namespace std;

bool check[101];

vector<int> a[101];

int result{ 0 };

void dfs(int start) {
	queue<int> q;
	q.push(start);
	//방문 했다고 표시
	check[start] = true;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i{ 0 }; i < a[x].size(); i++) {
			int y = a[x][i];
			if (!check[y]) {
				dfs(y);
				result++;
			}
		}

	}


}


int main() {
	
	int count, virusCount;
	int from, to;
	cin >> count >> virusCount;

	while (virusCount--) {
		cin >> from >> to;
		a[from].push_back(to);
		a[to].push_back(from);
	}


		dfs(1);
	
	cout << result;



	return 0;
}