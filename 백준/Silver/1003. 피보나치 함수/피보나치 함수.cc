#include<iostream>
using namespace std;



int main() {
    
    int result{ 0 };
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int arr[43]{ 0,1,1 };
	for (int i{ 3 }; i < 41; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}


	int count, inputNum;

	cin >> count;
	while (count--) {
		cin >> inputNum;
		if (inputNum == 0) {
			cout << 1 << " " << 0 << "\n";
			continue;
		}
		if (inputNum == 1) {
			cout << 0 << " " << 1 << "\n";
			continue;
		}
		cout << arr[inputNum - 1] << " " << arr[inputNum] << "\n";
	}

	return 0;
}