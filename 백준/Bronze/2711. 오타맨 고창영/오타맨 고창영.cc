#include<iostream>
#include<string>
using namespace std;



int main() {

	int count;
	cin >> count;
	while (count--) {
		int index;
		string input;
		cin >> index >> input;

		cout << input.substr(0, index-1) 
			<< input.substr(index)<<"\n";

	}
}