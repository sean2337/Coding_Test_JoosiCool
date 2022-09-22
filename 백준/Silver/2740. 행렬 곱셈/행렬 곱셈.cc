#include<iostream>
using namespace std;

int array1[101][101];
int array2[101][101];
int resultArr[101][101];


int main() {

	int N, M, K;


	cin >> N >>M;

	for (int i{ 0 }; i < N; i++) {
		for (int k{ 0 }; k < M; k++) {
			cin >> array1[i][k];
		}
	}

	
	cin >> M >> K;
	for (int i{ 0 }; i < M; i++) {
		for (int j{ 0 }; j < K; j++) {
			cin >> array2[i][j];
		}
	}


	for (int i{ 0 }; i < N; i++) {
		for (int j{ 0 }; j < K; j++) {
			for (int o{ 0 }; o < M; o++) {
				resultArr[i][j] += array1[i][o] * array2[o][j];
			}
		}
	}

	for (int i{ 0 }; i < N; i++) {
		for (int j{ 0 }; j < K; j++) {
			cout << resultArr[i][j] << " ";
		}
		cout << "\n";
	}



	return 0;

}