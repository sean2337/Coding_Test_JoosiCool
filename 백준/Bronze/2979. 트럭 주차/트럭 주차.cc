#include<iostream>
#include<string>
#include<vector>
using namespace std;


int fee[4];
bool arr[3][101];


int main() {

	int result = 0;

	for (int i = 1; i <= 3; i++) {
		cin >> fee[i];
		fee[i] *= i;
	}
	int start, end;
	for (int i = 0; i < 3; i++) {
		cin >> start >> end;
		for (int j = start; j < end; j++) {
			arr[i][j] = true;
		}
	}

	for (int i = 0; i <= 100; i++) {
		int count = 0;
		if (arr[0][i]) count++;
		if (arr[1][i]) count++;
		if (arr[2][i]) count++;
		result += fee[count];
	}
	cout << result << '\n';

	return 0;
}