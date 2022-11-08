#include<iostream>
#include<algorithm>
using namespace std;

int arr[103];



int main() {
	
	int slimeCount;
	cin >> slimeCount;
	int input;
	for (int i{ 0 }; i < slimeCount; i++) {
		cin >> input;
		arr[i] = input;
	}

	sort(arr, arr + slimeCount);

	int result{0};

	for (int i{ 1 }; i < slimeCount; i++) {
		result += arr[i] * arr[i - 1];
		arr[i] = arr[i] + arr[i - 1];
		
	}

	cout << result;



	return 0;
}