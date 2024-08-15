#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;

ll N,num;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	priority_queue<ll, vector<ll>, greater<ll>>que;

	for (int i = 0; i < N * N; i++) {
		cin >> num;
		que.push(num);
		if (que.size() > N) {
			que.pop();
		}
	}

	cout << que.top();

	return 0;
}