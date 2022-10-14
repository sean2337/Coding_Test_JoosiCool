#include<iostream>
using namespace std;

int main() {

	long long int num1, num2, max;

	cin >> num1 >> num2;
	if (num1 > num2)
		max = num1;
	else {
		max = num2;
	}
	int i{ 1 };
    long long int check;
	while (true) {
		check = max*i;
		if ((check % num2 == 0) && ((check % num1 == 0))) {
			cout<< check;
			break;
		}
		else {
			i++;
		}
	}

	return 0;
}