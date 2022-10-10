#include<iostream>
using namespace std;


int main() {

	int input;
	cin >> input;

	//홀수라면 상근이가 이기고, 짝수면 창영이가 이기는 구조이다.
	//이는 코드가 어렵다기 보다는 직접 경우의 수를 나열하는 것이 중요한 문제


	if (input % 2 == 0) {
		cout << "CY";
	}
	else {
		cout << "SK";
	}



	return 0;
}