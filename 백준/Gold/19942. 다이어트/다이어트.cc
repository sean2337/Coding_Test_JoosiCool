#include<iostream>
#include<string>
#include<vector>
#include<array>
#include <limits>
#include<map>
#include<algorithm>
using namespace std;

int N;
int gm1, gm2, gm3, gm4;
int m1, m2, m3, m4, m;
vector<array<int,5>> vec;

int minMoney = numeric_limits<int>::max();
int result = -1;
//key는 최소 비용
map<int, vector<vector<int>>> ret_v;

int main() {
	
	cin >> N;
	cin >> gm1 >> gm2 >> gm3 >> gm4;

	for (int i = 0; i < N; i++) {
		cin >> m1 >> m2 >> m3 >> m4 >> m;
		vec.push_back({ m1, m2, m3, m4, m });
	}


	for (int i = 1; i < (1<<N); i++) {

		int sumM1 = 0; int sumM2 = 0; int sumM3 = 0; int sumM4 = 0;
		int curM = 0;
		vector<int>plusVec;
		for (int j = 0; j < N; j++) {
			if (i & (1 << j)) {
				plusVec.push_back(j+1);
				sumM1 += vec[j][0];
				sumM2 += vec[j][1];
				sumM3 += vec[j][2];
				sumM4 += vec[j][3];
				curM += vec[j][4];
			}
			if (curM > minMoney) {
				break;
			}
		}
		
		if (sumM1 < gm1 || sumM2 < gm2 || sumM3 < gm3 || sumM4 < gm4)continue;
		if (curM <= minMoney) {
			minMoney = curM;;
			ret_v[minMoney].push_back(plusVec);
		}
	}

	if (minMoney == numeric_limits<int>::max() ) {
		cout << -1;
		return 0;
	}

	sort(ret_v[minMoney].begin(), ret_v[minMoney].end());
	cout << minMoney << '\n';
	for (int a : ret_v[minMoney][0]) {
		cout << a << ' ';
	}


	return 0;
}