#include <iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

int main() {
	
	string in;
	vector<string>resultArr;


	while (true)
	{
		stack<char>input;
		string result;
		//문자열을 받아서 문자형 스택에 저장
		getline(cin, in);
		bool ox{ false };
		if (in == ".")
			break;

		for (int i{ 0 }; i < in.size(); i++) {

			if (in[i] == '(' || in[i] == '[') {
				input.push(in[i]);
			}

			if (in[i] == ')') {

				if (!(input.empty()) && (input.top() == '(')) {
					input.pop();
				}

				else {
					ox = 0;
					break;
				}
			}

			if (in[i] == ']') {
				if (!(input.empty()) && (input.top()) == '[') {
					input.pop();
				}
				else {
					ox = 0;
					break;
				}
			}


			if (input.empty()) {
				ox = 1;
			}
			else {
				ox = 0;
			}

		}




		if (ox == 1) {
			resultArr.push_back("yes");
		}
		else {
			resultArr.push_back("no");
		}


	};



	for (string i : resultArr) {
		cout << i << "\n";
	}
}