#include<iostream>
#include<algorithm>
using namespace std;

int arr1[53];
int arr2[53];

bool checkBig(int num1, int num2)
{
	if (num1 > num2) {
		return true;
	}
	else {
		return false;
	}
}



int main() {
	int count;
	int result{ 0 };

	cin >> count;
	int input1, input2;
	for (int i{ 0 }; i < count; i++)
	{
		cin >> input1;
		arr1[i] = input1;
	}
	for (int i{ 0 }; i < count; i++)
	{
		cin >> input2;
		arr2[i] = input2;
	}



	sort(arr1, arr1 + count, checkBig);
	sort(arr2, arr2 + count);

	for (int i{ 0 }; i < count; i++)
	{
		result = result + arr1[i] * arr2[i];
	}

	cout << result;

	return 0;
}