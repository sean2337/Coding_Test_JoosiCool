#include<bits/stdc++.h>
using namespace std;

long long N, l, r, x, num;
vector<int>vec;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		vec.push_back(num);
	}
	cin >> x;

	sort(vec.begin(), vec.end());
	l = 0; r = vec.size() - 1;
	int cnt = 0;
	while (l < r) {
		int sum = vec[l] + vec[r];
		if (sum == x) {
			cnt++;
			l++; r--;
		}
		else if (sum > x) {
			r--;
		}
		else {
			l++;
		}
	}
	cout << cnt;


	return 0;
}