#include<iostream>
#include<string>
using namespace std;

int main() {

	int result{ 0 };

	string input;
	cin >> input;

	for (int i{ 0 }; i < input.length()+2; i++) {
		if (input[i] == NULL)
			break;

		if (input[i] == 'c') {
			if ((input[i + 1] == '=')||(input[i + 1] == '-')) {
				
				i++;
			}
			
			
		}
		else if (input[i] == 'd') {
			if (input[i + 1]=='-') {
				
				i++;
			}
			else if (input[i + 1] == 'z') {
				if (input[i + 2] == '=') {
					
					i = i + 2;
				}
			}
		
		}
		else if ((input[i] == 'n')|| (input[i] == 'l')) {
			if (input[i + 1] == 'j') {
				
				i++;
			}
		
		}
		else if ((input[i] == 's') || (input[i] == 'z')) {
			if (input[i+1]=='=') {
			
				i++;
			}
			
		}
		result++;


	}
	
	cout << result;


	return 0;
}