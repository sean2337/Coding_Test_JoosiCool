#include<iostream>
#include<stack>
#include<string>
using namespace std;



int main() {

	string result = "";

	stack<int>stk;
	int count;
	int input;
	int checkNum{ 1 };
	cin >> count;
	for (int i{ 0 }; i < count; i++)
	{
		cin >> input;
		while (true) {
			if (checkNum > count+1)
			{
				cout << "NO" << "\n";
				return 0;
			}

			if (stk.empty()) {

				stk.push(checkNum);
				result += "+\n";
				checkNum++;

			}
			else if (stk.top() == input) {
				result += "-\n";
				stk.pop();
				break;
			}
			else {
				stk.push(checkNum);
				result += "+\n";
				checkNum++;
		
			}

		}
		


	}

	if (stk.empty() != 1) {
		cout << "NO" << endl;
	}
	else {
		cout << result;
	}


	return 0;
}