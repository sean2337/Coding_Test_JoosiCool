#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
using namespace std;

int N;
string s;

class human {
public: 
	string alpha;
	int num;


	human(string alpha, int num) {
		this->alpha = alpha;
		this->num = num;
	}

	bool operator<(const human& other) const {
		if (alpha == other.alpha) {
			return num < other.num;
		}
		return alpha < other.alpha;
	}

	bool operator==(const human& other) const {
		return alpha == other.alpha && num == other.num;
	}

};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<human>lineList;
	vector<human>lineSortList;
	stack<human>waitStk;

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> s;
			string alpha = s.substr(0, 1);
			int num = stoi(s.substr(2));
			lineList.push_back(human(alpha, num));
			lineSortList.push_back(human(alpha, num));
		}
	}

	sort(lineSortList.begin(), lineSortList.end());
	int curIdx = 0;

	for (int i = 0; i < N * 5; i++) {

		// 넘어가진다면? 
		if (lineSortList[curIdx] == lineList[i]) {
			curIdx++;
		}
		else if (!waitStk.empty() && waitStk.top() == lineSortList[curIdx]) {
			// 스택에서 빠진다면?
			curIdx++;
			waitStk.pop();
			i--;
		}
		else {
			waitStk.push(lineList[i]);
		}
	}
	bool flag = true;
	
	while (waitStk.size()) {

		if (waitStk.top() == lineSortList[curIdx]) {
			curIdx++;
			waitStk.pop();
		}
		else {
			flag = false;
			break;
		}
	}

	string result = "GOOD";
	if (!flag) result = "BAD";

	cout << result;

	return 0;
}