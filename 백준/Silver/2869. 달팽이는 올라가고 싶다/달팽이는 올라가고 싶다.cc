#include<iostream>
#include<string>
using namespace std;

int main() {

	int high;
	int low;
	int tree;
	int result{ 1 };

	cin >> high >> low >> tree;

	result += (tree-high) / (high - low);
	if ((tree-high) % (high - low) != 0) {
		result++;
	}
	if (high >= tree) {
		result = 1;
	}
	cout << result;


	return 0;
}