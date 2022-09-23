#include<iostream>
using namespace std;

int main() {

	int a, b;
	cin >> a >> b;

	int num;
	int maxNum{ 1 };
	int minNum{ 1 };
	
	if (a > b) {
		num = b;
	}
	else {
		num = a;
	}

	for (int i{ 2 }; i < num + 1; i++) {
		if (a % i == 0&&b%i==0) {
			maxNum = i;
		}
	}

	for (int k{ 1 };k>0; k++) {
		
		if (((num * k) % a == 0) && ((num * k) % b == 0))
		{
			minNum = num*k;
			break;
		}	
	}
	

	cout << maxNum << "\n";
	cout << minNum;



	return 0;

}