#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;




int main() {

    //데크 선언
	deque<int>array;

	int size;
	int num;
    
	cin >> size >> num;
    
    // 1~size까지 데크 생성
	for (int i{ 1 }; i < size+1; i++) {
		array.push_back(i);
	}

	cout << "<";


	while (true) {
		
        //뽑힐 순서가 아니라면 뒤로 이동
		for (int k{ 0 }; k < num-1; k++) {
			array.push_back(array.front());
			array.pop_front();
		}
        
        //뽑힐 순서인 요소 출력하고 삭제
		cout << array.front();
		array.pop_front();
		
        //다 출력했다면 break
		if (array.empty() == 1)
		{
			cout << ">";
			break;
		}
			
		cout << ", ";
	}



	return 0;

}