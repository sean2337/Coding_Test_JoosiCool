#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


string arr[1005];

int main() {

	string inputStr;

	cin >> inputStr;

	for (int i{ 0 }; i < inputStr.length(); i++) {
		arr[i] = inputStr.substr(i);
	}

	sort(arr, arr + inputStr.length());

	for (int i{ 0 }; i < inputStr.length(); i++) {
		cout << arr[i] << "\n";
	}


	return 0;
}