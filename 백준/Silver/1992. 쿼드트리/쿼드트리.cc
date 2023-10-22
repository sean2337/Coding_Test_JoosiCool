#include<bits/stdc++.h>
using namespace std;

char arr[67][67];
int N;

string quadTreeFun(int y, int x, int n) {

	string result = "";
	char b = arr[y][x];

	if (n == 1) {
		return string(1, arr[y][x]);
	}


	for (int ny = y; ny < n + y; ny ++) {
		for (int nx = x; nx < n + x; nx++) {
			if (arr[ny][nx] != b) {
				result += "(";
				result += quadTreeFun(y, x, n / 2);
				result += quadTreeFun(y, x + n/2, n / 2);
				result += quadTreeFun(y + n/2, x, n / 2);
				result += quadTreeFun(y + n / 2, x + n / 2, n / 2);
				result += ")";
				return result;
			}
		}
	}
	return string(1, arr[y][x]);
}


int main() {
	
	string in;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> in;
		for (int j = 0; j < N; j++) {
			arr[i][j] = in[j];
		}
	}

	cout << quadTreeFun(0, 0, N);

	return 0;
}