#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include <algorithm>
#include<set>
#include <sstream>
#include <limits>
#include<math.h>
 using namespace std;

int arr[1026];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int k;
	cin >> k;

	for (int i = 1; i < pow(2, k); i++) {
		cin >> arr[i];
	}

	int start = pow(2, k-1);
	int plus = pow(2,k);

	while (plus != 1) {
		for (int i = start; i <= pow(2, k); i += plus) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		plus = plus / 2;
		start = start / 2;
	}
	return 0;
}