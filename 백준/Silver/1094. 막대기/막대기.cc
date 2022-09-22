#include<iostream>
using namespace std;


int main() {

	int num;
	int result{ 0 };
	cin >> num;


	while (num != 0) {
		if (num / 64 >= 1) {
			num = num - 64;
			result++;
		}

		else if (num / 32 >= 1) {
			num = num - 32;
			result++;
		}

		else if (num / 16 >= 1) {
			num = num - 16;
			result++;
		}

		else if (num / 8 >= 1) {
			num = num - 8;
			result++;
		}


		else if (num / 4 >= 1) {
			num = num - 4;
			result++;
		}

		else if (num / 2 >= 1) {
			num = num - 2;
			result++;
		}

		else if (num / 1 >= 1) {
			num = num - 1;
			result++;
		}


	}

	cout << result;
	



	return 0;

}