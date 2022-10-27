#include<iostream>
#include<algorithm>
using namespace std;


int main() {

	int arr[5];
	int input;
	int average{ 0 };
	int mid;
	for (int i{ 0 }; i < 5; i++)
	{
		cin >> input;
		average += input;
		arr[i] = input;
	}

	sort(arr, arr + 5);
	average = average / 5;
	mid = arr[2];

	cout << average << "\n" << mid;



	return 0;
}