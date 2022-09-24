#include<iostream>
#include<string>
using namespace std;

char inputArr[51][51];

string example1[8] = { "WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW", "WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW" };
string example2[8] = { "BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB" };

int chess1(int x, int y) {

	int checkNum{ 0 };

	for (int i{ 0 }; i < 8; i++) {
		for (int j{ 0 }; j < 8; j++) {
			if (inputArr[i + x][j + y] != example1[i][j])
				checkNum++;
		}
	}

	return checkNum;
}

int chess2(int x, int y) {

	int checkNum{ 0 };

	for (int i{ 0 }; i < 8; i++) {
		for (int j{ 0 }; j < 8; j++) {
			if (inputArr[i + x][j + y] != example2[i][j])
				checkNum++;
		}
	}

	return checkNum;
}





int main() {

	int row;
	int column;
	int result{ 64 };

	cin >> row >> column;

	
	//배열 입력 받기
	for (int i{ 0 }; i < row; i++) {
		for (int k{ 0 }; k < column; k++) {
			cin >> inputArr[i][k];
		}
	}


	int minNum{ 0 };
	//example 배열과 맞는지 확인
	for (int i{ 0 }; i+8 <= row; i++) {
		for (int k{ 0 }; k+8 <= column; k++) {
			int chs1= chess1(i, k);
			int chs2= chess2(i, k);
			if(chs1<chs2)  {
				minNum = chs1;
			}
			else {
				minNum = chs2;
			}

			if (result > minNum)
				result = minNum;

		}
	}

	cout << result;

	return 0;

}