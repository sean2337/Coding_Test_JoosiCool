#include<bits/stdc++.h>
using namespace std;

int arr[1000003];
int rnt[1000003];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	memset(rnt, -1, sizeof(arr));
	stack<int>stk;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> arr[i];

		while (!stk.empty()) {
			if (arr[stk.top()] < arr[i]) {
				rnt[stk.top()] = arr[i];
				stk.pop();
			}
			else {
				break;
			}
		}
		stk.push(i);
	}

	for (int i = 0; i < T; i++) {
		cout << rnt[i] << ' ';
	}
	return 0; 
};