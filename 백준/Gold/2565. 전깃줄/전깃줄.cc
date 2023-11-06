#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<int, int>>vec;
int N, num, a, b;
int len;
int lis[1000];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		vec.push_back({ a,b });
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++) {
		int num = vec[i].second;
		auto pos = lower_bound(lis, lis + len, num);
		if (*pos == 0) len++;
		*pos = num;
	}
	cout << N - len;

	return 0;
}