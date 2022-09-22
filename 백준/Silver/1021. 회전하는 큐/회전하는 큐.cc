#include<iostream>
#include<deque>
using namespace std;

int main() {
	
	int size;
	int count;
	int result{ 0 };
	cin >> size >> count;

	deque<int> input;
	for (int i{ 1 }; i < size+1; i++) {	
		input.push_back(i);
	}
	
	int num;

	for (int k{ 0 }; k < count; k++) {
	

		cin >> num;
		int numEx{0};

	

		for (int u{ 0 }; u < input.size(); u++) {
			if (num == input[u]) {
				numEx = u;
				break;
			}
		}




		if (numEx < input.size()-numEx) {
			while (true) {
				if (input.front() == num) {
					input.pop_front();
					break;
				}
				else {
					input.push_back(input.front());
					input.pop_front();
					result++;
				}
			}
			
		}

		else{
			while (true) {
				if (input.front() == num) {
					input.pop_front();
					break;
				}
				else {
					input.push_front(input.back());
					input.pop_back();
					result++;
				}
			}
			
		}
	};


	cout << result;



	return 0;

}