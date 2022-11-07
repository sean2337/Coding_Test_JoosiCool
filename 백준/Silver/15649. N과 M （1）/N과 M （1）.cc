#include<iostream>
#include<queue>
#include<vector>
using namespace std;

bool visit[9]{0};
int a[9]{0};
int M, N;

void dfs(int start) {
	
	if (start == M)
	{
		for (int i{ 0 }; i < M; i++) {
			cout << a[i] << ' ';
		}
		cout << "\n";
		return;
	}

	for (int i{ 1 }; i <= N; i++) {
		if (!visit[i])
		{
			visit[i] = true;
			a[start] = i;
			dfs(start + 1);
			visit[i] = false;
		}
	}

}


int main() {

	cin >> N >> M;
	dfs(0);

	return 0;
}