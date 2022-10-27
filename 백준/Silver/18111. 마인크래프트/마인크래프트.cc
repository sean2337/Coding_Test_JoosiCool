#include<iostream>
#include<algorithm>
using namespace std;

int arr[250005];


int main() {

	int N, M ,B;
	int inputHigh;
	cin >> N>>M;

	//블록의 보유 개수
	cin >> B;
	int count = N * M;

	// 배열에 높이 입력
	for (int i{ 0 }; i < count; i++) {
		cin >> inputHigh;
		arr[i] = inputHigh;
	}

	int time{ 0x7f7f7f7f };
	int highResult;

	for (int i{ 0 }; i < 257; i++)
	{
		int needBlock{ 0 };
		int eraseBlock{ 0 };
		for (int k{ 0 }; k < count; k++)
		{
			if (arr[k] - i > 0) {
				eraseBlock += arr[k]-i;
			}
			else if(arr[k] - i < 0) {
				needBlock += i - arr[k];
			}
		}
		if (eraseBlock + B >= needBlock) {
			if (time >= eraseBlock * 2 + needBlock) {
				time = eraseBlock * 2 + needBlock;
				highResult = i;
			}
		}


	}

	cout << time<<" "<<highResult;



	return 0;
}