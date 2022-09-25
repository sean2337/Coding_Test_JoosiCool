#include<iostream>
using namespace std;

int main() {
	
	int input;
	cin >> input;

	int minResult{ input };



	for (int i{ 1 }; i <= input; i++) {
		int result{ i };
		int N = i;
		while (true) {
			result = result + (N % 10);
			N = N / 10;
			if (N == 0)
				break;
		}
		

		if (result == input) {
			if (i < minResult) {
				minResult = i;
			}
		}
	}

	if (minResult == input) {
		cout << 0;
	}
	else {
		cout << minResult;
	}


	return 0;

}