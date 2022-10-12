#include<iostream>
#include<algorithm>

using namespace std;

int arr[1005];


int main() {

	int count, snakeLen;

	cin >> count >> snakeLen;

	for (int i{ 0 }; i < count; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + count);

	for (int i{ 0 }; i < count; i++) {
		if (arr[i] <= snakeLen) {
			snakeLen++;
		}
		else 
			break;
	}

	cout << snakeLen;

	return 0;
}