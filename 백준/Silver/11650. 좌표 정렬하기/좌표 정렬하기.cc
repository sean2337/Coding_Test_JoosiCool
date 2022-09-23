#include<iostream>
#include<algorithm>
using namespace std;


//x,y를 담을 구조체 생성
struct xxyy {
	int x;
	int y;
};

// 어떤 것이 더 큰지 확인 해주는 함수
bool check(xxyy a, xxyy b) {

	if (a.x == b.x) {
		return a.y < b.y;
	}
	else {
		return a.x < b.x;
	}

}


//구조체 배열 생성
xxyy arr[100001];


int main() {

	//반복횟수 변수 선언 및 입력받음.
	int count;
	cin >> count;


	//x,y를 받음
	for (int i{ 0 }; i < count; i++) {
		cin >> arr[i].x >> arr[i].y;
	}

	//sort 알고리즘 활용
	sort(arr, arr + count, check);


	//정렬된거 출력
	for (int i{ 0 }; i < count; i++) {
		cout << arr[i].x << " " << arr[i].y << "\n";
	}




	return 0;

}