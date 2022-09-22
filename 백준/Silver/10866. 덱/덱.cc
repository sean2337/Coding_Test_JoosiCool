#include<iostream>
#include<deque>
#include<string>
#include<stdio.h>
#pragma warning(disable:4996)
using namespace std;


int main() {
	
	deque<int> input;
	int count;
	int num;
	string inputStr;

	cin >> count;


	while (count--) {

		cin >> inputStr;


		if (inputStr == "push_front") {
			cin >> num;
			input.push_front(num);
		}

		
		else if (inputStr == "push_back") {
			cin >> num;
			input.push_back(num);

		}

		else if (inputStr == "pop_front") {
			if (input.empty() == 1) {
				cout << -1 << "\n";
			}
			else {
				cout << input.front() << "\n";
				input.pop_front();
			}
		}


		else if (inputStr == "pop_back") {

			if (input.empty() == 1) {
				cout << -1 << "\n";
			}
			else {
				cout << input.back() << "\n";
				input.pop_back();
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
			else
			{
				cout << input.back() << "\n";
			}
		}

	}


	return 0;

}