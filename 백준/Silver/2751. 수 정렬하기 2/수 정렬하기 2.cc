#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

	int count;

	int inNum;
	vector<int>input;

	cin >> count;

	for (int i{ 0 }; i < count; i++) {
		cin >> inNum;
		input.push_back(inNum);
	}

	sort(input.begin(), input.end());

	for (int k : input)
		cout << k << "\n";



	return 0;
}