#include<iostream>
#include<string>
#include<deque>
using namespace std;


int main() {

	deque<int>card;

	int num;
	cin >> num;

	for (int i{ 1 }; i < num + 1; i++) {
		card.push_back(i);
	}

	while (true) {

		cout << card.front() << "\n";
		card.pop_front();

		if (card.empty() == 1) {
			break;
		}

		card.push_back(card.front());
		card.pop_front();
		
	}
	



	return 0;

}