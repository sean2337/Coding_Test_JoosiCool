#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
#include<algorithm>

using namespace std;



int main() {

	int count;
	cin >> count;

	int a = 1;
	int b = 0;
	int change;

	for (int i{ 0 }; i < count; i++)
	{
		change = a;
		a = b;
		b = change + b;

	}

	cout << a << " " << b;


	return 0;
}