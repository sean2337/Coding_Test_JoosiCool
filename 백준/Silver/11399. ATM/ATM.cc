#include<iostream>
#include<algorithm>
using namespace std;


int arr[1003];

int main() {
	int count, input{0};
	cin >> count;

	int plus{ 0 };

	for (int i{ 0 }; i < count; i++)
	{
		cin >> input;
		arr[i] = input;
	}

	sort(arr, arr + count);

	int result{ 0 };


	
	for (int i{ 0 }; i < count; i++)
	{
		result += (arr[i]+plus);
		plus += arr[i];
	}


	cout << result;

	return 0;
}