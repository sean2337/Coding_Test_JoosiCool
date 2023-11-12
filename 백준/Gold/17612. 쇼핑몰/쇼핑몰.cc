#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;
struct Cacher {
	ll id, maxTime, casher_id;
};

struct comp {
	bool operator()(Cacher a, Cacher b) {
		if (a.maxTime == b.maxTime) {
			return a.casher_id > b.casher_id;
		}
		return a.maxTime > b.maxTime;
	}
};
bool cmp2(const Cacher& a, const Cacher& b) {
	if (a.maxTime == b.maxTime) {
		return a.casher_id > b.casher_id;
	}
	return a.maxTime < b.maxTime;
}

priority_queue<Cacher, vector<Cacher>, comp>que;
vector<Cacher>vec;
const ll INF = 987654321;
ll N, K;
ll id, c;


int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;

	for (ll i = 0; i < N; i++) {
		cin >> id >> c;
		if (i < K) {
			que.push({ id , c ,i + 1 });
			continue;
		}
		vec.push_back(que.top());
		c += que.top().maxTime;
		ll newCashwerId = que.top().casher_id;
		que.pop();
		que.push({ id,c,newCashwerId });
	}

	while (que.size()) {
		vec.push_back(que.top());
		que.pop();
	}
	ll rnt = 0;
	sort(vec.begin(), vec.end(), cmp2);
	for (int i = 0; i < vec.size(); i++) {
		rnt += vec[i].id * (i + 1);
	}
	cout << rnt;

	return 0;
}