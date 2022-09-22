#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {


	int inNum;
	vector<int>input;

	cin >> inNum;

	while (true) {

		input.push_back(inNum % 10);

		inNum = inNum / 10;
		if (inNum == 0) {
			break;
		}
		
	}

	sort(input.begin(), input.end());
	reverse(input.begin(), input.end());

	for (int i : input)
		cout << i;


	return 0;
}