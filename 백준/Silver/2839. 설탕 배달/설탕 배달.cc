#include<iostream>
#include<string>
using namespace std;



int main() {

	int count;
	cin >> count;

	//3으로 얼만큼 나눌 수 있는가.
	int div = count / 3;
	int minNum{ 0 };
	int result{ 5000 };
	//i는 3의 봉지개수
	for (int i{ 0 }; i <= count; i++) {
		int courage = count - 3 * i;
		if (courage < 0)
			continue;

		if (courage % 5 == 0) {
			minNum = courage / 5 + i;
			if (minNum < result)
				result = minNum;
		}

	}
	if (result == 5000) {
		cout << -1;
	}
	else {
		cout << result;
	}

}