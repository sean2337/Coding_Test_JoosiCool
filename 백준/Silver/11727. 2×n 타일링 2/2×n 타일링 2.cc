#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<map>
using namespace std;




int main() {
	
	int arr[1003];
	arr[1] = 1;
	arr[2] = 3;

	int inputNum;
	cin >> inputNum;
	
	if (inputNum == 1 || inputNum == 2) {
		cout << arr[inputNum];
	}
	else {
		for (int i{ 3 }; i <= inputNum; i++)
		{
			arr[i] = (arr[i - 1]  + arr[i - 2]*2) % 10007;	
		}

		cout << arr[inputNum];
	}




	return 0;
}