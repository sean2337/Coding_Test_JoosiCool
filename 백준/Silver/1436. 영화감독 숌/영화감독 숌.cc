#include<iostream>
#include<string>
using namespace std;


int chagneTitle(int n) {

	

	int count{0};
	int j = 666;

	while (true)
	{
		string str = to_string(j);

		for (int i{ 0 }; i < str.size() - 2; i++) {
			if (str[i] == '6' && str[i + 1]=='6' && str[i + 2]=='6') {
				count++;
				if (count == n) {
					return j;
				}
				break;
			}
		}
		j++;

	}
	
}



int main() {

	int input;
	cin >> input;

	
	cout << chagneTitle(input);


}