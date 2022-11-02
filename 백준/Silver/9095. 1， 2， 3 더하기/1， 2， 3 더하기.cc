#include<iostream>
using namespace std;

int Fun(int a)
{
	if (a == 1) {
		return 1;
	}
	else if (a == 2) {
		return 2;
	}
	else if (a == 3) {
		return 4;
	}
	else {
		return (Fun(a - 1) + Fun(a - 2)+Fun(a-3));
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int count;
	cin >> count;
	int inputNum;

	while (count--)
	{
		cin >> inputNum;
		cout << Fun(inputNum) << "\n";
	}

	return 0;
}