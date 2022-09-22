#include <iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

int main() {

	string in;
	vector<string>resultArr;
	int count;

	cin>>count;


	while (count--)
	{
		stack<char>input;
		cin.ignore();
		//문자열을 받아서 문자형 스택에 저장
		cin >> in;
		bool ox{ false };


		for (int i{ 0 }; i < in.size(); i++) {

			if (in[i] == '(' ) {
				input.push(in[i]);
			}

			else if (in[i] == ')') {

				if (!(input.empty()) && (input.top() == '(')) {
					input.pop();

				}

				else {
					ox = 0;
					break;
				}
			}

			else {
				ox = 0;
				break;
			}



			if (input.empty()) {
				ox = 1;
			}
			else {
				ox = 0;
			}

		}




		if (ox == 1) {
			resultArr.push_back("YES");
		}
		else {
			resultArr.push_back("NO");
		}


	};



	for (string i : resultArr) {
		cout << i << "\n";
	}
}