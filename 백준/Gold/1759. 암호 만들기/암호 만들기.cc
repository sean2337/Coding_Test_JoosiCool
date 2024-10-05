#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;

ll L, C;
char c;
vector<char>vec;
vector<string> resultVec;
ll rnt;

// cnt1 = 모음이 개수, cnt2 = 자음의 개수
void solution(ll idx, ll cnt1, ll cnt2, string s) {
	if(idx >= C){
		if (s.size() == L && cnt1 >= 1 && cnt2 >= 2) {
			resultVec.push_back(s);
		}
		return;
	}

	solution(idx + 1, cnt1, cnt2, s);
	s = s + vec[idx];
	if (vec[idx] == 'a' || vec[idx] == 'e' || vec[idx] == 'i' || vec[idx] == 'o' || vec[idx] == 'u') {
		solution(idx + 1, cnt1 + 1, cnt2, s);
	}
	else {
		solution(idx + 1, cnt1, cnt2 + 1, s);
	}
}


int main() {

	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> c;
		vec.push_back(c);
	}

	sort(vec.begin(), vec.end());
	
	solution(0, 0, 0, "");
	reverse(resultVec.begin(), resultVec.end());

	for (string s : resultVec) {
		cout << s << "\n";
	}
	return 0;
}