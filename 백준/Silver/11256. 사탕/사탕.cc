#include<iostream>
#include<algorithm>
using namespace std;

bool check(int a, int b) {
	if (a > b)
		return true;
	else {
		return false;
	}
}

int boxArr[1005];

int main() {

	int count;
	int candy;
	int boxCount;
	int width,length;

	cin >> count;

	while (count--) {
		int result{ 0 };

		cin >> candy >> boxCount;

		for (int i{ 0 }; i < boxCount; i++)
		{
			cin >> width >> length;
			boxArr[i] = width * length;
		}

		sort(boxArr, boxArr + boxCount, check);

		for (int i{ 0 }; i < boxCount; i++)
		{
			if (candy <= 0)
				break;
			candy = candy - boxArr[i];
			result++;
		}

		cout << result << "\n";
	}


	return 0;
}