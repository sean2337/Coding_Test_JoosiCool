#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int arr[103];

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int count;
	cin >> count;
	int input;
	for (int i{ 0 }; i < count; i++)
	{
		cin >> input;
		arr[i] = input;
	}

	int result{ 0 };
	int num;
	cin >> num;

	for (int i{ 0 }; i < count; i++)
	{
		if (arr[i] == num) {
			result++;
		}
	}

	cout << result;

	return 0;
}