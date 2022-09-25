#include<iostream>
using namespace std;

int resultArr[1000001]{ 1 };

bool IsPrime(int num) {

	if (num < 2) {
		return false;
	}

	for (int i{ 2 }; i * i <= num; i++) {
		if (num % i == 0) {
			return false;
		}
	}

	return true;

}


int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int M, N;
	cin >> M >> N;

	int sum{ 0 };
	int min{ 100000 };

	for (int i{ M }; i <= N; i++) {
		if (IsPrime(i)) {
			sum += i;
			if (i < min) {
				min = i;
			}
		}

	}

	if (sum == 0) {
		cout << -1;
	}
	else
	{
		cout << sum << "\n" << min;
	}


	return 0;

}