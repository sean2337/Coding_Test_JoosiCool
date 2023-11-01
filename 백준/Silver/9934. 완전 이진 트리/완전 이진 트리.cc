#include<bits/stdc++.h>
using namespace std;

vector<int>vec;
int K, plusNum, start, num;

int main() {

	cin >> K;
	for (int i = 0; i < pow(2,K)-1; i++) {
		cin >> num;
		vec.push_back(num);
	}
	start = vec.size() / 2;
	plusNum = vec.size() + 1;

	while (plusNum != 1) {
		for (int i = start; i < vec.size(); i += plusNum) {
			cout << vec[i] <<" ";
		}
		cout << '\n';
		plusNum = plusNum / 2;
		start = start / 2;
	}
	return 0;
}