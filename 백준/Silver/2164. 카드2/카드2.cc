#include<iostream>
#include<deque>
using namespace std;

int main() {

	deque<int>array;

	int count;

	cin >> count;

	for (int i{ 1 }; i <= count; i++) {
		array.push_back(i);
	}

	for (int k{ 0 }; k < count-1; k++) {
		array.pop_front();
		array.push_back(array.front());
		array.pop_front();
	}

	cout << array.front();
	
	return 0;

}