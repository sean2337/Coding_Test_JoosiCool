#include<bits/stdc++.h>
using namespace std;

bool isNumber(char c) {
	return (c >= '0' && c <= '9');
}

bool cmp(string a, string b) {
	if (a.size() != b.size()) return a.size() < b.size();

	for (int i = 0; i < a.size(); i++) {
		if (a[i] == b[i]) continue;
		return a[i] < b[i];
	}
	return false;

}

string frontZeroErase(string s) {

	string result = "";
	bool flag = false;
	for (char c : s) {
		if (c != '0') {
			flag = true;
			result += c;
		}
		else {
			if (flag) result += c;
		}
	}
	
	if (!flag) return "0";
	return result;
}


int main() {
	
	int T;
	string s;
	vector<string>result;
	cin >> T;
	while (T--) {
		cin >> s;
		string plus = "";
		for (char c : s) {
			if (isNumber(c)) {
				plus += c;
			}
			else {
				if (plus.size()) {
					result.push_back(frontZeroErase(plus));
					plus = "";
				}
			}
		}
		if(plus.size()) result.push_back(frontZeroErase(plus));
	}


	sort(result.begin(), result.end(), cmp);
	for (string s : result) {
		cout << s << '\n';
	}
	return 0;
};