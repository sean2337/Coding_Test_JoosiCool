#include<iostream>
using namespace std;

int fun(int k, int n) {
	if (k == 0) {
		return n;
	}

	else if (n == 1) {
		return 1;
	}

	else {
		return fun(k - 1, n) + fun(k, n - 1);
	}
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int count;

	cin >> count;

	int k, n;

	for (int i{ 0 }; i < count; i++) {
		cin >> k >> n;
		cout << fun(k, n) << "\n";
	}


	return 0;

}