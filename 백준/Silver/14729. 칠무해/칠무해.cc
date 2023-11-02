#include<bits/stdc++.h>
using namespace std;

int N;
float num;
priority_queue<float, vector<float>, greater<float>> pq;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		pq.push(num);
	}
	N = 7;
	while (N--) {
		cout << fixed << std::setprecision(3) << pq.top()<<'\n';
		pq.pop();
	}
	
	return 0;
}