#include<iostream>
#include<algorithm>
using namespace std;

struct scoreStr {
	int score;
	int index;
};

bool FunScore(scoreStr a, scoreStr b)
{
	if (a.score > b.score)
		return true;
	else
		return false;
}


bool FunIndex(scoreStr a, scoreStr b)
{
	if (a.index < b.index)
		return true;
	else
		return false;
}


int main() {

	scoreStr input[9];

	for (int i{ 1 }; i < 9; i++) {
		cin >> input[i].score;
		input[i].index = i;
	}

	sort(input + 1, input + 9, FunScore);
	int sum{ 0 };
	for (int i{ 1 }; i < 6; i++) {
		sum += input[i].score;
	}
	cout << sum << "\n";

	sort(input + 1, input + 6, FunIndex );

	for (int i{ 1 }; i < 6; i++) {
		cout<< input[i].index << " ";
	}

}