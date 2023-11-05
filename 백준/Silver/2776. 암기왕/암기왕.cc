#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int T, N, S, num;
vector<int>vec1;


bool findNum(int goal) {
	int start = 0, end = N - 1, mid;
	while (start<=end) {
		mid = (start + end) / 2;
		if (goal == vec1[mid])return true;
		if (goal < vec1[mid]) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return false;
}



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> N;
		vec1.clear();
		for (int i = 0; i < N; i++) {
			cin >> num;
			vec1.push_back(num);
		}
		sort(vec1.begin(), vec1.end());
		cin >> S;
		for (int i = 0; i < S; i++) {
			cin >> num;
			if (findNum(num)) cout << 1 << '\n';
			else cout << 0 << "\n";
		}
	}
	
	return 0;
}
