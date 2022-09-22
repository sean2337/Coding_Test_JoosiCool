#include<iostream>
using namespace std;

struct human {

	int height;
	int weight;

};


int main() {
	
	human arr[50];

	int rank{ 1 };
	int count;
	cin >> count;
	int inHeight;
	int inWeight;

	for (int i{ 0 }; i < count; i++) {
		cin >> inHeight >> inWeight;
		arr[i].height = inHeight;
		arr[i].weight = inWeight;
	}

	for (int i{ 0 }; i < count; i++) {
		for (int j{ 0 }; j < count; j++) {
			if ((arr[i].height < arr[j].height) && (arr[i].weight < arr[j].weight)) {
				rank++;
			}
		}
		cout << rank<< " ";
		rank = 1;
	}


}

