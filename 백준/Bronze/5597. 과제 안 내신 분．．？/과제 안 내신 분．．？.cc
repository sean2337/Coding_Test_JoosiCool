#include<iostream>
using namespace std;

bool arr[31]{0};

int main() {


	int input;
	for (int i{ 0 }; i < 28; i++) {
		cin >> input;
		arr[input] = 1;
	}

	for (int i{ 1 }; i < 31; i++) {

		if (arr[i] == 0) {
			cout << i << "\n";
		}
	}

	return 0;
}