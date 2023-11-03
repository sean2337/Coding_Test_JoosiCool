#include<bits/stdc++.h>
using namespace std;


deque<char> que;
deque<char>result;
string inStr, findStr;
char lastC;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> inStr >> findStr;
	lastC = findStr[findStr.size() - 1];
	
	for (char c : inStr) {
		result.push_back(c);

		if (result.back() == lastC) {
			que.clear();
			for (int i = findStr.size() - 1; i >= 0; i--) {
				if (result.size() && findStr[i] == result.back()) {
					que.push_back(result.back());
					result.pop_back();
				}
				else {
					while (que.size()) {
						result.push_back(que.back()); que.pop_back();
					}
					break;
				}
			}
		}
	}
	if (!result.size()) {
		cout << "FRULA";
		return 0;
	}
	for (char c : result) {
		cout << c;
	}
	

	return 0;
}