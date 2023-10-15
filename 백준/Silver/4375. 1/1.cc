#include<iostream>
#include<string>
#include<vector>
#include<array>
#include <limits>
#include<map>
#include<set>
#include<algorithm>
using namespace std;



int main() {

	int n;

	while (cin>>n) {

		int check = 1;
		int count = 1;
		//0일때까지 계속함.
		while (!(check % n == 0)) {
			check = check * 10 + 1;
			check %= n;
			count++;
		}
		cout << count << '\n';
	}


	return 0;
}