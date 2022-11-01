#include<iostream>
using namespace std;

long long A, B, C;

long long ex;

long long Fun(long long B) {
	if (B == 0) return 1;
	if (B == 1) return A % C;

	ex = Fun(B / 2) % C;
	if (B % 2 == 0) return ex * ex % C;
	return ex * ex % C * A % C;
}


int main() {
	cin >> A >> B >> C;

	cout << Fun(B);



	return 0;
}