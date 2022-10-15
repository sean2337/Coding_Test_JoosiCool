#include<iostream>
#include<algorithm>
using namespace std;

int arr[100005];

bool check(int a, int b) {
	if (a > b) {
		return 1;
	}
	else {
		return 0;
	}
}

int main() {

	int count;
	cin >> count;

	for (int i{ 0 }; i < count; i++) {
		cin >> arr[i];
	}
	
	sort(arr, arr+count,check);

	for (int i{ 0 }; i < count; i++) {
		arr[i]=arr[i]+i+1;
	}

	sort(arr, arr + count, check);

	cout << arr[0]+1 << endl;

	return 0;
}