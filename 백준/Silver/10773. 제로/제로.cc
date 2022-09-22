#include <iostream>
#include <string>
#include <stack>
using namespace std;


int main(void) {
	stack<int> stacks;
	int count;
	cin >> count;

	for (int i = 0; i < count; i++) {
		int num;
		cin >> num;
		if (num != 0) {
			stacks.push(num);
		}
		else {
			stacks.pop();
		}
	}

	int sum = 0;

	while (!stacks.empty()) {
		sum +=stacks.top();
		stacks.pop();
	}

	cout << sum;

}