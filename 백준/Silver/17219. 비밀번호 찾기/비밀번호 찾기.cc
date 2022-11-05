#include<iostream>
#include<string>
#include<map>
using namespace std;


map<string, string>hashMap;


int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int inCount;
	int findCount;

	string inAddress, inName;

	cin >> inCount >> findCount;

	for (int i{ 0 }; i < inCount; i++) {
		cin >> inAddress >> inName;
		hashMap[inAddress] = inName;
	}

	for (int i{ 0 }; i < findCount; i++) {
		cin >> inAddress;
		cout << hashMap[inAddress] << "\n";
	}


	return 0;
}