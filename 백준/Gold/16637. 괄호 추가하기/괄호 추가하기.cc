#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>calChoiceVec;
vector<int>numVec;
vector<char>calVec;
int ret = -987654321;


int oper(char a, int b, int c) {
	if (a == '+') {
		return b + c;
	}
	if (a == '-') {
		return b - c;
	}
	if (a == '*') {
		return b * c;
	}
}

void go(int here, int num) {
	if (here == numVec.size() - 1) {
		ret = max(ret, num);
		return;
	}
	//기존에 있던거에서 그대로 계산진행
	go(here + 1, oper(calVec[here], num, numVec[here + 1]));

	if (here + 2 <= numVec.size() - 1) {
		int temp = oper(calVec[here + 1], numVec[here + 1], numVec[here + 2]);
		go(here + 2, oper(calVec[here], num, temp));
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	char c;
	int N;
	cin >> N;
	while (N--) {
		cin >> c;
		if (c >= '0' && c <= '9') {
			numVec.push_back(c - '0');
		}
		else {
			calVec.push_back(c);
		}
	}

	go(0, numVec[0]);
	cout << ret;

	return 0;
}