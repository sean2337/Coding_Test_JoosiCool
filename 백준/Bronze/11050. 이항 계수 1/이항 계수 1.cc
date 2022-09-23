#include<iostream>
#include<algorithm>
using namespace std;

// 이항계수 출력 함수(조합 활용)
int combination(int n, int r) {


	if (r == 0||r==n) {
		return 1;
	}
	


	return combination(n - 1, r - 1) + combination(n - 1, r);
}


int main() {

	int n, k;

	cin >> n >> k;

	cout << combination(n, k);


	return 0;

}