#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pairInt;

int N;
vector<vector<int>> vec;
int arr[24][24];

void combination(int start, vector<int>v) {
	if (v.size() == N/2) {
		vec.push_back(v);
		return;
	}

	for (int i = start; i < N; i++) {
		v.push_back(i);
		combination(i+1, v);
		v.pop_back();
	}
	return;
}

int sumScore(vector<int> v) {
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			sum += arr[v[i]][v[j]]; sum += arr[v[j]][v[i]];
		}
	}
	return sum;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	
	vector<int>ve;
	combination(0, ve);
	int minResult = 98765421;
	for (vector<int>v : vec) {
		vector<int> firstVec;
		vector<int> secondVec;
		for (int i = N-1; i >= 0; i--) {
			if (v.size() && i == v[v.size() - 1]) {
				firstVec.push_back(i);
				v.pop_back();
			}
			else{
				secondVec.push_back(i);
			}
		}
		minResult = min(minResult, abs(sumScore(firstVec) - sumScore(secondVec)));
	}

	cout << minResult;

	return 0;
}