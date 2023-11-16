#include<iostream>
#include<string>
using namespace std;

int main() {

	int result{ 0 };

	string input;
	cin >> input;

	for (int i{ 0 }; i < input.length(); i++) {
		if ((input[i] == 'A') || (input[i] == 'B') || (input[i] == 'C')) {
			result += 3;
		}
		if ((input[i] == 'D') || (input[i] == 'E') || (input[i] == 'F')) {
			result += 4;
		}
		if ((input[i] == 'G') || (input[i] == 'H') || (input[i] == 'I')) {
			result += 5;
		}
		if ((input[i] == 'J') || (input[i] == 'K') || (input[i] == 'L')) {
			result += 6;
		}
		if ((input[i] == 'M') || (input[i] == 'N') || (input[i] == 'O')) {
			result += 7;
		}
		if ((input[i] == 'P') || (input[i] == 'Q') || (input[i] == 'R') || (input[i] == 'S')) {
			result += 8;
		}
		if ((input[i] == 'T') || (input[i] == 'U') || (input[i] == 'V')) {
			result += 9;
		}
		if ((input[i] == 'W') || (input[i] == 'X') || (input[i] == 'Y') || (input[i] == 'Z')) {
			result += 10;
		}
	

	}
	
	cout << result;


	return 0;
}