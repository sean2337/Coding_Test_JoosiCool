#include<iostream>
#include<string>
using namespace std;

int main() {

	string input;
	
	int count;
	cin >> count;
	int result{ 0 };

	for (int i{ 0 }; i < count; i++) {
		bool check{ false };
		cin >> input;
		for (int k{ 1 }; k < input.length(); k++) {
			for (int j{ 0 }; j < k; j++) {
				if ((input[k] != input[k - 1]) && (input[k] == input[j])) {
					check = true;
					break;
				}
			}
			
		}

		if (check == false) {
			result++;
		}

	}

	cout << result;





	return 0;
}