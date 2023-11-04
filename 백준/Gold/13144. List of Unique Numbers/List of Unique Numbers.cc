#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;
int visited[100004];
vector<int> vec;

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


	ll l = 0, r = 0, cnt = 0;
	while (r<N) {
		if (!visited[vec[r]]) {
			visited[vec[r]]++;
			r++;
		}
		else {
			cnt += (r - l);
			visited[vec[l]]--;
			l++;
		}
	}
	cnt += ll((r - l) * (r - l + 1) / 2);

	cout << cnt;
	
	return 0;
}