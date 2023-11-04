#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int N, goal;
vector<int>vec;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		vec.push_back(num);
	}
	cin >> goal;

	sort(vec.begin(), vec.end());

	int l = 0, r = N-1;
	int rnt = 0;
	while (l < r) {
		int sum = vec[l] + vec[r];
		if (sum == goal) rnt++;
		if (sum > goal) {
			r--;
		}
		else {
			l++;
		}
	}
	cout << rnt;
	
	return 0;
}