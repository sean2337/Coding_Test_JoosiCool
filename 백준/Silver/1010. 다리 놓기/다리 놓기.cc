#include<iostream>
using namespace std;





int main() {
	int count;
	int num1, num2;
	cin >> count;

	while (count--) {
		cin >> num1 >> num2;

		long long result{ 1 };
		int exNum{ 1 };

		for (int i{ num2 }; i > num2 - num1; i--) {
			result *= i;
			result /= exNum++;
		}


		cout << result<<"\n";



	}

}