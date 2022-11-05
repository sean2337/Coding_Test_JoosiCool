#include<iostream>
using namespace std;


int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);


	long long input;
	long long Sum{0};
	int cnt{0};
	cin >> input;
	int plus{ 1 };
	while (true) {
		Sum = Sum + plus;
		cnt++;
		if (input < Sum) {
			cnt--;
			break;
		}

		plus++;

	}

	cout << cnt;
	return 0;
}