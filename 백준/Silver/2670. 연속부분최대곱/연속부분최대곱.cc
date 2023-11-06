#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

double prefixMul[10004];
double arr[100004];
int N;

double threePrint(double a) {
	a *= 1000;
	a = round(a);
	return(a /= 1000);
}

int main() {
	prefixMul[0] = 1;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	double mul = arr[0];
	double ret = 0;
	for (int i = 1; i < N;i++) {
		if (mul * arr[i] < arr[i]) {
			mul = arr[i];
		}
		else {
			mul *= arr[i];
		}
		ret = max(ret, mul);
	}

	
	printf("%.3lf", ret + 0.00001);

	return 0;
}