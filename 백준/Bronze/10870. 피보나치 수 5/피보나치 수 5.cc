#include<iostream>
#include<string>
using namespace std;


int pivoFun(int num) {
	if (num == 0)
		return 0;
	else if (num == 1)
		return 1;
	else {
		return(pivoFun(num - 1) + pivoFun(num - 2));
	}
	
}



int main() {
	int num;
	cin >> num;
	cout << pivoFun(num);

}