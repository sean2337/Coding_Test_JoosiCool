#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<map>
using namespace std;




int main() {
	
	int arr[1001];
	arr[1] = 1;
	arr[2] = 2;

	int inputNum;
	cin >> inputNum;
	
	if (inputNum == 1 || inputNum == 2) {
		cout << inputNum;
	}
	else {
		for (int i{ 3 }; i <= inputNum; i++)
		{
			arr[i] = (arr[i - 1] + arr[i - 2])%10007;
		}

		cout << arr[inputNum];
	}




	return 0;
}