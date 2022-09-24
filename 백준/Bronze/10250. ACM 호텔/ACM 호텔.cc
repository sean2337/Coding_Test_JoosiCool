#include<iostream>
using namespace std;


int main() {

	int count;
	cin >> count;

	int h, w, n;
	int result{ 0 };

	for (int i{ 0 }; i < count; i++) {
		cin >> h >> w >> n;

		int h1 = n % h;
		int w1 = n / h;
		if (h1 == 0) {
			h1 = h;
		}
		else {
			w1++;
		}
		result = h1 * 100 + w1;
		cout << result << "\n";

	}


	return 0;

}