#include<iostream>
using namespace std;


int main() {

	int cardArray[100];

	int count;
	cin >> count;
	int blackJack;
	cin >> blackJack;

	for (int i{ 0 }; i < count; i++) {
		cin >> cardArray[i];
	}

	int maxNum{ 0 };
	int checkNum;

	for (int i{ 0 }; i < count-2; i++) {
		for (int j{ i+1 }; j < count-1; j++) {
			for (int o{ j+1 }; o < count; o++) {
				checkNum = cardArray[i] + cardArray[j] + cardArray[o];
				if (checkNum<=blackJack && checkNum>maxNum)
					maxNum = checkNum;
			}
		}
	}

	cout << maxNum;


	return 0;

}