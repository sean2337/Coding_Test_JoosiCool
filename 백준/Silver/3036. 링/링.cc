#include<iostream>
#include<algorithm>
using namespace std;

int Circle[100];

int main() {

	int count,radius;
	cin >> count;

	for (int i{ 0 }; i < count; i++)
	{
		cin >> radius;
		Circle[i] = radius;
	}

	int num1, num2;
	int smallNum;

	for (int i{ 1 }; i < count; i++)
	{
		num1 = Circle[0];
		num2 = Circle[i];
		if (num1 > num2)
		{
			smallNum = num2;
		}
		else
			smallNum = num1;

		for (int k{ smallNum }; k > 0; k--) {
			if (num1 % k == 0 && num2 % k == 0)
			{
				num1 = num1 / k;
				num2 = num2 / k;
			}
		}

		cout << num1 << '/' << num2 << endl;

	}


	return 0;
}