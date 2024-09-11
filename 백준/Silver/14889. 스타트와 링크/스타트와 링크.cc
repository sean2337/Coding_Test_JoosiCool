#include<iostream>
#include<string>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<tuple>
using namespace std;
typedef pair<int, int>pairInt;


const int maxN = 24;
int visited[maxN];
int arr[maxN][maxN];
int N;
int rnt = 98765421;

void go(int i, int sum1, int sum2, vector<int> vec1, vector<int> vec2) {

	if (i == N) {
		rnt = min(rnt, abs(sum1 - sum2));
		return;
	}

	if (vec1.size() < N / 2) {

		int plusValue = 0;
		for (int a : vec1) {
			plusValue += arr[i][a];
			plusValue += arr[a][i];
		}

		vec1.push_back(i);
		go(i + 1, sum1 + plusValue, sum2, vec1, vec2);
		vec1.pop_back();
	}

	if (vec2.size() < N / 2) {

		int plusValue = 0;
		for (int a : vec2) {
			plusValue += arr[i][a];
			plusValue += arr[a][i];
		}

		vec2.push_back(i);
		go(i + 1, sum1, sum2 + plusValue, vec1, vec2);
		vec2.pop_back();
	}
}


int main() {

	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> arr[y][x];
		}
	}

	vector<int>vec1;
	vector<int> vec2;
	go(0, 0, 0, vec1, vec2);


	cout << rnt;

	return 0;
}