#define _CRT_SECURE_NO_WARNINGS 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;
using namespace std;
const ll INF = 987654321;
ll N, num;

struct compare{
	bool operator()(const ll a, const ll b) {
		if (abs(a) == abs(b)) {
			return a > b;
		}
		return abs(a) > abs(b);
	}
};



priority_queue<ll, vector<ll>, compare>que;


int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	while (N--) {
		cin >> num;
		if (num == 0) {
			if (que.empty()) {
				cout << 0 << '\n';
			}
			else {
				cout << que.top() << '\n';
				que.pop();
			}
		}
		else {
			que.push(num);
		}
	}
	return 0;
}