#include<iostream>
#include<string>
#include<vector>
#include<array>
#include <limits>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

int n = 9;
int k = 7;
int arr[9];
pair<int, int>findValue;

int totalSum = 0;


void findTwo() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] + arr[j] == totalSum - 100) {
				findValue.first = i;
				findValue.second = j;
				return;
			}
		}
	}
	return;
}



int main() {

	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		totalSum += arr[i];
	}
	sort(arr, arr + 9);
	findTwo();
	for (int i = 0; i < 9; i++) {
		if (i == findValue.first || i == findValue.second) continue;
		cout << arr[i] << '\n';
	}

	return 0;
}