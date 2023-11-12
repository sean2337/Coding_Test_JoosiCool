#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;
ll arr[100004];
ll visited[10004];
ll N, M, x, y;

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (ll i = 0; i < M; i++) {
		cin >> x >> y;
		arr[x]++; arr[y]--;
	}

	for (ll i = 1; i <= N; i++) {
		arr[i] += i;
		visited[arr[i]]++;
	}
	bool flag = false;
	for (ll i = 1; i <= N; i++) {
		if (visited[i] >= 2 || visited[i] == 0) flag = true;
	}

	if (flag) {
		cout << -1;
	}
	else {
		for (ll i = 1; i <= N; i++) {
			cout << arr[i] << " ";
		}
	}

	return 0;
}