#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int count;
	cin >> count;

	vector<int>inArr(count);
	int input{0};


	for (int i{ 0 }; i < count; i++) {
		cin >> inArr[i];
	}

	sort(inArr.begin(), inArr.end());
	

	int countOut;
	cin >> countOut;

	for (int i{ 0 }; i < countOut; i++) {
		cin >> input;
		auto startIndex = upper_bound(inArr.begin(), inArr.end(), input);
		auto endIndex=lower_bound(inArr.begin(), inArr.end(), input);
		cout << startIndex - endIndex << " ";
	}


	return 0;

}