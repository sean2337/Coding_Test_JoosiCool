#include<iostream>
using namespace std;

bool dot[50]{ 0 };

int main() {

	int num1, num2, div;
	cin >> num1 >> num2 >> div;

	if (num1 % num2==0)
	{
		cout << 0;
		return 0;
	}

	if (num1 > num2)
		num1 = num1 % num2;

	int result;
	for (int i{ 0 }; i < div; i++)
	{
		num1 = num1 * 10;
		result = num1 / num2;
		num1 = num1 % num2;
	}

	cout << result;
		

	return 0;
}