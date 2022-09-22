#include<iostream>
#include<string>
using namespace std;


int main() {

	string input;
	int count{ 0 };
	cin >> input;

	
	while (input.size()!=1) {
		int num{0};
		count++;
		for (int i{ 0 }; i < input.size(); i++) {
			num = num +  int(input[i])-48;
		}

		input = to_string(num);
		
	}
	
	cout << count << "\n";
	if ((input == "3")|| (input == "6")|| (input == "9")) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}

	return 0;

}