#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<map>
using namespace std;

string monNameArr[100001];
map<string, int>m1;


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int docuCount, outCount;
	string monName;

	cin >> docuCount>>outCount;

	for (int i{ 1 }; i <= docuCount; i++) {
		cin >> monName;
		monNameArr[i] = monName;
		m1.insert(make_pair(monName,i));
	}


	string findIt;
	int n;
	for (int i{ 1 }; i <= outCount; i++) {
		cin >> findIt;
		//숫자가 입력됬는지 체크
		if (isdigit(findIt[0]) == true) {
			n = stoi(findIt);
			cout << monNameArr[n]<<"\n";
		}
		//몬스터 이름이 입력되었다면,
		else {
			auto it = m1.find(findIt);
			cout << it->second << "\n";
		}

	}




	return 0;
}