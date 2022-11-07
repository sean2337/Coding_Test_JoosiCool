#include<iostream>
using namespace std;


int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);


	int num;
	int result;
	int one, ten, hund;
	cin >> num;
	if (num <100) {
		result = num;
	}

	else if (num == 1000) {
		result = 144;
	}
	else {
		result = 99;

		for (int i{ 100 }; i <= num; i++) {
			int ex = i;
			one = ex % 10;
			ex = ex / 10;
			ten = ex % 10;
			ex= ex / 10;
			hund = ex % 10;
			if (hund + one == ten * 2)
				result++;
		}

	}

	cout << result;

	return 0;
}