#include<iostream>
using namespace std;



int main() {

	double x1, y1;
	double x2, y2;
	double x3, y3;

	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;

    //벡터 외적 사용
	double external = (x1 * y2 - x2 * y1 + x2 * y3 - x3 * y2 + x3 * y1 - x1 * y3);

	if (external == 0) {
		cout << 0;
	}
    //외적이 1보다 크면 반시계
	else if (external > 0) {
		cout << 1;
	}
    //외적이 1보다 작으면 시계
	else {
		cout << -1;
	}
	



	return 0;

}