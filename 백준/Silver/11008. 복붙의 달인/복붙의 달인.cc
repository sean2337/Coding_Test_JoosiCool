#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {

	int count;
	string input;
	string copy;
	cin >> count;
	while (count--) {
		int result{ 0 };
		cin >> input >> copy;
		for (int i{ 0 }; i < input.length(); i++) {
			result++;

			if (input.substr(i, copy.length()) == copy)
			{
				i = i + copy.length()-1;
			}
			
		}
		cout << result << "\n";

	}
	return 0;
}