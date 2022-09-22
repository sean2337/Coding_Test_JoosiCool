#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct Human
{
	int age;
	string name;
};


bool Check(Human a,  Human b) {
	return a.age < b.age;
}



int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int age;
	string name;

	int count;
	cin >> count;

	Human *array =new Human [100001];

	for (int i{ 0 }; i < count; i++) {
		cin >> array[i].age >> array[i].name;		
	}
	
	stable_sort(array, array+count, Check);


	for (int k{ 0 }; k < count; k++) {
		cout << array[k].age << " " << array[k].name << "\n";
	}



	return 0;

}