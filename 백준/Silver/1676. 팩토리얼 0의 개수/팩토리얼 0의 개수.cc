#include<iostream>
using namespace std;



int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int input;
	int result{ 0 };
	int two{ 0 };
	int five{ 0 };
	cin >> input;
	int ex;
	for (int i{ 1 }; i <= input; i++) {
		int ex = i;
		while (true)
		{
			if (ex % 10 == 0) {
				ex = ex / 10;
				result++;
			}
			else if (ex % 5 == 0) {
				ex = ex / 5;
				five++;
			}
			else if (ex % 2 == 0) {
				ex = ex / 2;
				two++;
			}
			else
				break;
		}
	}
	

	if (two > five) {
		result += five;
	}
	else {
		result += two;
	}

	cout << result;

	return 0;
}