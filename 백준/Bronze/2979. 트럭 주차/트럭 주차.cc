#include<iostream>
#include<string>
using namespace std;


int fee[4];
int arr[101];


int main() {

	int result = 0;

	for (int i = 1; i <= 3; i++) {
		cin >> fee[i];
		fee[i] *= i;
	}
	int start, end;
	for (int i = 0; i < 3; i++) {
		cin >> start >> end;
		for (int j = start; j < end; j++) {
			arr[j]++;
		}
	}

	for (int i = 0; i < 100; i++) {
		result += fee[arr[i]];
	}
	cout << result << '\n';

	return 0;
}