#include<iostream>
#include<string>
using namespace std;

const int MOD = 1234567891;
const int MulNum = 31;


int main() {


	string input;
	int count;
	cin >> count;
	cin >> input;

	long long result{ 0 };
	long long hash{ 1 };

	for (int i{ 0 }; i < input.length(); i++) {
		
		result = (result + hash * (input[i]-'a'+1)) % MOD;
		
		hash = (hash * MulNum)%MOD;

	}

	cout << result;


	return 0;
}