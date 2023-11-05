#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pairInt;
int N, num;
vector<int>numVec;
vector<char>operVec;
int maxResult = numeric_limits<int>::min();
int minResult = numeric_limits<int>::max();


int cal(int a, int b, char c) {
	if (c == '+') return a + b;
	if (c == '-') return a - b;
	if (c == '*') return a * b;
	return a / b;
}

int calculate() {
	int result = numVec[0];
	for (int i = 0; i < N-1; i++) {
		result = cal(result, numVec[i + 1], operVec[i]);
	}
	return result;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		numVec.push_back(num);
	}

	cin >> num; while (num--) operVec.push_back('+');
	cin >> num; while (num--) operVec.push_back('-');
	cin >> num; while (num--) operVec.push_back('*');
	cin >> num; while (num--) operVec.push_back('/');
	sort(operVec.begin(), operVec.end());
	do{
		int rnt = calculate();
		minResult = min(minResult, rnt);
		maxResult = max(maxResult, rnt);
	} while (next_permutation(operVec.begin(), operVec.end()));

	cout << maxResult << '\n' << minResult;

	return 0;
}
