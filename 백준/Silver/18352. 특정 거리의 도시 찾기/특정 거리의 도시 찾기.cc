#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair < ll, ll>pairll;

const ll maxN = 300004;

vector<ll>vec[maxN];
ll N, M, K, X, num1, num2;
ll visited[maxN];


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0);

	cin >> N >> M >> K >> X;

	// 배열 생성
	while (M--) {
		cin >> num1 >> num2;
		vec[num1].push_back(num2);
	}

	vector<ll> resultVec;
	queue<ll>que;
	que.push(X);
	visited[X] = 1;

	while (que.size()) {
		ll queSize = que.size();
		for (ll i = 0; i < queSize; i++) {
			ll current = que.front(); que.pop();

			for (ll n : vec[current]) {
				if (visited[n] != 0) continue;
				visited[n] = visited[current] + 1;
				if (visited[n] - 1 == K) resultVec.push_back(n);
				que.push(n);

			}
		}
	}

	sort(resultVec.begin(), resultVec.end());
	if (resultVec.size() == 0) {
		cout << -1;
		return 0;
	}
	string result = "";
	for (ll r : resultVec) {
		result += (to_string(r) + "\n");
	}
	cout << result;
	
	return 0;
}