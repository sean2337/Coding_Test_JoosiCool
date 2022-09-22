#include<iostream>
#include<vector>
using namespace std;


int main() {

	int num;
	cin >> num;

	int input{ 0 };
	
	int result{ 0 };

	for (int i{ 0 }; i < num; i++) {
		int ex{ 0 };
		cin >> input;
		for (int k{ 1 }; k < input + 1; k++) {
			if (input % k == 0) {
				ex++;
			}
		}
		if (ex == 2) {
			result++;
		}
	}



	cout << result;

	return 0;

}