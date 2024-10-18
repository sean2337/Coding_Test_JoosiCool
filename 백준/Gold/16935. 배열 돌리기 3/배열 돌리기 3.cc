#include<iostream>
#include<queue>
#include <utility>
using namespace std;

const int maxN = 104;
int arr[maxN][maxN];
int copyArr[maxN][maxN];

int yLen, xLen, K, kind;


void copyArrFun() {

	for (int x = 0; x < xLen; x++) {
		for (int y = y = 0; y < yLen; y++) {
			copyArr[y][x] =  arr[y][x];
		}
	}

}

void printArr() {
	for (int y = 0; y < yLen; y++) {
		for (int x = 0; x < xLen; x++) {
			cout << arr[y][x] << " ";
		}
		cout << '\n';
	}
}

//1번 연산
void reverseHeight(){
	for (int y = 0; y < yLen; y++) {
		for (int x = 0; x < xLen; x++) {
			arr[y][x] = copyArr[yLen - 1 - y][x];
		}
	}
}

//2번 연산
void reverseWidth() {
	for (int y = 0; y < yLen; y++) {
		for (int x = 0; x < xLen; x++) {
			arr[y][x] = copyArr[y][xLen - 1 - x];
		}
	}
}

//3번 연산
void rotateRight() {
	int num = yLen;
	yLen = xLen;
	xLen = num;
	for (int y = 0; y < yLen; y++) {
		for (int x = 0; x < xLen; x++) {
			arr[y][x] = copyArr[xLen - x - 1][y];
		}
	}
}


//4번 연산
void rotateLeft() {
	int num = yLen;
	yLen = xLen;
	xLen = num;
	for (int y = 0; y < yLen; y++) {
		for (int x = 0; x < xLen; x++) {
			arr[y][x] = copyArr[x][yLen - y - 1];
		}
	}
}


//5번 연산
void divRotateRight() {
	// 4 => 1
	for (int y = 0; y < yLen / 2; y++) {
		for (int x = 0; x < xLen / 2; x++) {
			arr[y][x] = copyArr[y + yLen / 2][x];
		}
	}
	// 1 => 2
	for (int y = 0; y < yLen / 2; y++) {
		for (int x = xLen / 2; x < xLen; x++) {
			arr[y][x] = copyArr[y][x - xLen / 2];
		}
	}
	// 2 => 3
	for (int y = yLen / 2; y < yLen; y++) {
		for (int x = xLen / 2; x < xLen; x++) {
			arr[y][x] = copyArr[y - yLen / 2][x];
		}
	}
	// 3 => 4
	for (int y = yLen / 2; y < yLen; y++) {
		for (int x = 0; x < xLen / 2; x++) {
			arr[y][x] = copyArr[y][x + xLen / 2];
		}
	}
}

//6번 연산
void divRotateLeft() {
	// 1 => 4
	for (int y = 0; y < yLen / 2; y++) {
		for (int x = 0; x < xLen / 2; x++) {
			arr[y + yLen / 2][x] = copyArr[y][x];
		}
	}
	// 4 => 3
	for (int y = yLen / 2; y < yLen; y++) {
		for (int x = 0; x < xLen / 2; x++) {
			arr[y][x + xLen / 2] = copyArr[y][x];
		}
	}
	// 3 => 2
	for (int y = yLen / 2; y < yLen; y++) {
		for (int x = xLen / 2; x < xLen; x++) {
			arr[y - yLen / 2][x] = copyArr[y][x];
		}
	}
	// 2 => 1
	for (int y = 0; y < yLen / 2; y++) {
		for (int x = xLen / 2; x < xLen; x++) {
			arr[y][x - xLen / 2] = copyArr[y][x];
		}
	}
}



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> yLen >> xLen >> K;
	
	for (int y = 0; y < yLen; y++) {
		for (int x = 0; x < xLen; x++) {
			cin >> arr[y][x];
		}
	}

	while (K--) {

		cin >> kind;
		copyArrFun();

		if (kind == 1) {
			reverseHeight();
		}
		else if (kind == 2) {
			reverseWidth();
		}
		else if (kind == 3) {
			rotateRight();
		}
		else if (kind == 4) {
			rotateLeft();
		}
		else if (kind == 5) {
			divRotateRight();
		}
		else if (kind == 6) {
			divRotateLeft();
		}
	}
	printArr();

	return 0;
}