//이진탐색 문제
#include<iostream>
#include<algorithm>
using namespace std;

int arr[100001];
int inCount;
int outCount;

void fun(int n, int inArr[]) {
	int low{ 0 };
	int high{ inCount - 1 };
	int mid;

	while (low <= high) {

		mid = (low + high) / 2;
		
		if (inArr[mid] == n) {
			cout << '1' << "\n";
			return;
		}
		else if (inArr[mid] > n) {
			high = mid - 1;
		}
		else if (inArr[mid] < n) {
			low = mid + 1;
		}

	}

	cout << '0' << "\n";
	return;

}



int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> inCount;


	for (int i{ 0 }; i < inCount; i++) {
		int a;
		cin >> a;
		arr[i] = a;
	}


	sort(arr, arr + inCount);

	cin >> outCount;
	for (int i{ 0 }; i < outCount; i++) {
		int output;
		cin >> output;
		fun(output, arr);
	}
	

	return 0;

}