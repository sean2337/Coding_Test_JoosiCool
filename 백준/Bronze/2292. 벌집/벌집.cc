#include<iostream>
using namespace std;

int main() {
	
	int num;
	cin >> num;

	if (num == 1) {
		cout << 1;
		return 0;
	}
	else {
		num--;
	}
	int minus{ 0 };
	int count{ 0 };



	while (true) {
		num = num - minus;
		minus = minus + 6;
		count++;
		if (num <= 0)
			break;
	}

	cout << count;


	return 0;

}