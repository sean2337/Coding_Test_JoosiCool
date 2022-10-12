#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
#include<algorithm>
using namespace std;




int main() {

	int num1, num2;
	scanf("%d:%d", &num1, &num2);

	int div;
	if (num1 > num2)
		div = num2;
	else
		div = num1;

	for (int i{ div }; i > 0; i--) {
		if ((num1 % i == 0) && (num2 % i == 0)) {
			num1 = num1 / i;
			num2 = num2 / i;
		}
	}

	cout << num1 << ":" << num2;
	

	return 0;
}