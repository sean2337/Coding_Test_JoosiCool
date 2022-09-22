#include<iostream>
#include<stack>
#include<string>
#include<stdio.h>
#pragma warning(disable:4996)
using namespace std;


int main() {

	stack<int> input;
	int count;
	int num;
	string inputStr;

	cin >> count;


	while (count--) {

		cin >> inputStr;


		if (inputStr == "push") {
			cin >> num;
			input.push(num);
		}


		else if (inputStr == "pop") {
			if (input.empty() == 1) {
				cout << -1 << "\n";
			}
			else {
				cout << input.top() << "\n";
				input.pop();
			}
		}




		else if (inputStr == "size") {
			cout << input.size() << "\n";
		}

		else if (inputStr == "empty") {
			cout << input.empty() << "\n";
		}

		else if (inputStr == "top") {
			if (input.empty() == 1) {
				cout << -1 << "\n";
			}
			else {
				cout << input.top() << "\n";
			}
		}



	}


	return 0;

}