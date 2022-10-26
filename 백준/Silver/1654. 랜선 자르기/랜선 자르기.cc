#include<iostream>
#include<algorithm>
using namespace std;


int main() {

	int amount, need;

	cin >> amount >> need;
	int max{ 0 };

	int* LanArr = new int[amount];
	int input;
	for (int i{ 0 }; i < amount; i++) {
		cin >> input;
		if (max < input)
			max = input;
		LanArr[i] = input;
	}


	long long high = max;
	long long low = 1;
	long long mid;
	long long countLan{ 0 };
	long long result{0};

	while (low <= high) 
	{
		countLan = 0;
	
		mid = (high + low) / 2;
		for (int i{ 0 }; i < amount; i++)
		{
			countLan += LanArr[i] / mid;
		}

		if (countLan >= need) {
			low = mid+1;
			if (result < mid)
				result = mid;
		}
		else if (countLan < need) {
			high = mid-1;
		}


	}

	
	cout << result;


	return 0;
}