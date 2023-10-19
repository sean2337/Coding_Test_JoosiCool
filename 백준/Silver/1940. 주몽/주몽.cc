#include<iostream>
#include<string>
#include<vector>
#include<array>
#include <limits>
#include<map>
#include<set>
#include<algorithm>
using namespace std;


int arr[10000003];
int N, M;


int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] + arr[j] == M) result++;
		}
	}


	cout << result;

	return 0;
}