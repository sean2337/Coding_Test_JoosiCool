#include<iostream>
#include<cmath>
using namespace std;

int arr[1003];

int main() {

	int input1, input2;
	int count;
	cin >> input1 >> input2;
	cin >> count;

	for (int i{ 0 }; i < count; i++)
		cin >> arr[i];

	int minus{ abs(input1 - input2) };
	
	for (int i{ 0 }; i < count; i++)
	{
		if (abs(input2 - arr[i]) < minus) {
			minus = abs(input2 - arr[i]);
		}
	}
	
	if (minus == abs(input1 - input2)) {
		cout << minus;
	}
	else {
		cout << 1 + minus;
	}

	return 0;
}