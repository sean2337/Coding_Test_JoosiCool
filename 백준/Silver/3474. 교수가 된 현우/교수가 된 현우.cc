#include<bits/stdc++.h>
using namespace std;

long long rightZeroCnt(long long num) {
	long long result = 0;
	for (long long i = 5; num / i > 0; i *= 5) {
		result += num / i;
	}
	return result;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	long long num;
	while (T--) {
		cin >> num;
		cout<< rightZeroCnt(num)<<'\n';
	}
	
	return 0;
};