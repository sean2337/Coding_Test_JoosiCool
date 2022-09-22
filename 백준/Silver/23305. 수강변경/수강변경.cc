#include<iostream>
#include<vector>
using namespace std;


int main() {

	int array[1000001] = { 0 };
	int count;
	int inputNum;
	int changeNum;
	int output{ 0 };
	cin >> count;

	for (int i{ 0 }; i < count; i++) {
		cin >> inputNum;
		array[inputNum]++;
	}

	for (int k{ 0 }; k < count; k++) {
		cin >> changeNum;
		if (array[changeNum] > 0) {
			array[changeNum]--;
		}

	}

	for (int u : array) {
		output += u;
	}

	cout << output;

	return 0;

}