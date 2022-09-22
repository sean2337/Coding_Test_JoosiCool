#include<iostream>
#include<queue>
#include<string>
#include<stdio.h>
#pragma warning(disable:4996)
using namespace std;


int main() {

	queue<int> input;
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
				cout << input.front() << "\n";
				input.pop();
			}
		}




		else if (inputStr == "size") {
			cout << input.size() << "\n";
		}

		else if (inputStr == "empty") {
			cout << input.empty() << "\n";
		}

		else if (inputStr == "front") {
			if (input.empty() == 1) {
				cout << -1 << "\n";
			}
			else {
				cout << input.front() << "\n";
			}
		}

		else if (inputStr == "back") {
			if (input.empty() == 1) {
				cout << -1 << "\n";
			}
			else {
				cout << input.back() << "\n";
			}
		}



	}


	return 0;

}