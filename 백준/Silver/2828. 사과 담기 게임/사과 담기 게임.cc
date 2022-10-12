#include<iostream>
using namespace std;

int main() {

	int N, M;
	int count;
	int inputNum;

	cin >> N >> M;
	cin >> count;

	int start = 1;
	int end = M;
	int result{ 0 };
	while (count--)
	{
		cin >> inputNum;
		bool flag = true;
		while (flag) {
			if ((start <= inputNum) && (end >= inputNum))
			{
				flag = false;
			}
			else if (start > inputNum) {
				start--;
				end--;
				result++;
			}
			else {
				start++;
				end++;
				result++;
			}
		}
	}
	cout << result;

	return 0;
}