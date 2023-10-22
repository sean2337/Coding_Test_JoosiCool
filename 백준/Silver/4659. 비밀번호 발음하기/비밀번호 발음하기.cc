#include<bits/stdc++.h>
using namespace std;

char vowelArr[] = {'a', 'e', 'i', 'o', 'u'};


bool isVowel(char c) {
	for (char vowel : vowelArr)
	{
		if (vowel == c) return true;
	}
	return false;

}

bool isOneVowel(string s) {
	for (char c : s) {
		if (isVowel(c)) return true;
	}
	return false;
}

bool isThree(string s) {
	int count = 1;
	//모음이면 true 아니면 false
	bool flag = isVowel(s[0]);

	for (int i = 1; i < s.size(); i++) {
		if (flag == isVowel(s[i])) {
			count++;
			if (count >= 3) return false;
		}
		else {
			flag = isVowel(s[i]);
			count = 1;
		}
	}

	return true;
}


bool checkTwo(string s) {
	char before = s[0];
	for (int i = 1; i < s.size(); i++) {
		char c = s[i];
		if (before == c && c != 'e' && c != 'o') return false;
		else {
			before = c;
		}
	}
	return true;

}

bool checkWord(string s) {
	//모음이 한개라도 있는지 체크
	if (!isOneVowel(s)) return false;

	//연속3개는 안됨.
	if (!isThree(s)) return false;

	//같은 글자 연속 안됨 e, o는 제외
	if (!checkTwo(s)) return false;
	return true;


}


int main() {
	string c;
	while (true) {
		cin >> c;
		if (c == "end") break;
		if (checkWord(c)) {
			cout << "<" + c + "> is acceptable." << '\n';
		}
		else {
			cout << "<" + c + "> is not acceptable." << '\n';
		}
	}
	return 0;
};