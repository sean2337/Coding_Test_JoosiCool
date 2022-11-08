#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<map>
#include<cstring>
using namespace std;


int maxArr[303];
int arrStair[303];



int main() {
	

	int count;
	int input;
	cin >> count;
	for (int i{ 1 }; i <= count;i++) {
		cin >> input;
		arrStair[i] = input;
	}


	maxArr[1] = arrStair[1];
	maxArr[2] = arrStair[2]+arrStair[1];
	maxArr[3] = max(arrStair[1] + arrStair[3], arrStair[2] + arrStair[3]);

	for (int i{ 4 }; i <= count; i++) {

		if ((maxArr[i - 2] + arrStair[i]) > (maxArr[i - 3] + arrStair[i - 1] + arrStair[i])) {
			maxArr[i] = maxArr[i - 2] + arrStair[i];
		}
		else {
			maxArr[i] = maxArr[i - 3] + arrStair[i - 1] + arrStair[i];
		}
	}

	cout << maxArr[count];



	return 0;
}