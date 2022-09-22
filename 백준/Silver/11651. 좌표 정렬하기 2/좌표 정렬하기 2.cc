#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct xyxy
{
	int x;
	int y;
};


bool Check(xyxy a,  xyxy b) {
	if (a.y == b.y) {
		return a.x < b.x;
	}
	else {
		return a.y < b.y;
	}
}



int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int inX;
	int inY;

	int count;
	cin >> count;

	xyxy *array =new xyxy [100001];

	for (int i{ 0 }; i < count; i++) {
		cin >> array[i].x >> array[i].y;		
	}
	
	stable_sort(array, array+count, Check);


	for (int k{ 0 }; k < count; k++) {
		cout << array[k].x << " " << array[k].y << "\n";
	}



	return 0;

}