#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	

	string num;
	while (true) {
		cin >> num;
		if (num == "0")
			break;
		bool check{ 1 };
		for (int i{ 0 }; i < num.size(); i++) {
			
			if (num[i] != num[num.size() - i-1]) {
				check = 0;
				break;
			}
		}

		if (check == 1) {
			cout << "yes" << "\n";
		}
		else {
			cout << "no" << "\n";
		}

	}

	return 0;

}