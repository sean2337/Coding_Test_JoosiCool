#include<iostream>
#include<algorithm>
using namespace std;



int main() {

	long long treeCount;
	long long  wantTree;

	cin >> treeCount >> wantTree;
	int* treeArr = new int[treeCount];
	int inputTree;
	for (int i{ 0 }; i < treeCount; i++)
	{
		cin >> inputTree;
		treeArr[i] = inputTree;
	}

	long long high = 1000000000;
	long long low = 0;
	long long mid;
	long long cut_tree;
	long long ans{0};

	while (low <= high) {
		mid = (low + high) / 2;
		cut_tree = 0;

		for (int i{ 0 }; i < treeCount; i++) {
			if (treeArr[i] > mid) {
				cut_tree = cut_tree + treeArr[i] - mid;
			}
		}

		if (cut_tree == wantTree)
		{
			ans = mid;
			break;
		}
			
		

		else if (cut_tree > wantTree) {
			if (ans < mid) {
				ans = mid;
			}
			low = mid + 1;
		}
		else if (cut_tree < wantTree) {
			high = mid - 1;
		}

	}
	cout << ans;
	delete[] treeArr;

	return 0;
}