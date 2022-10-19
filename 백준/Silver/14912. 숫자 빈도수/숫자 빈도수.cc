#include<iostream>
#include<string>
using namespace std;


int main() {


	int input;
	char check;

	int result{ 0 };

	cin >> input >> check;

	for (int i{ 1 }; i <= input; i++) {

		string iStr = to_string(i);

		for (int k{ 0 }; k < iStr.length(); k++)
		{
			if (iStr[k] == check)
				result++;
		}
	
	}

	cout << result;

	return 0;
}