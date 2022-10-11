#include<iostream>
#include<string>
using namespace std;

struct human {
	string name;
	int day;
	int month;
	int year;
};


human arr[105];

int main() {



	int count;
	cin >> count;

	for (int i{ 0 }; i < count; i++) {
		cin >> arr[i].name >> arr[i].day >> arr[i].month >> arr[i].year;
	}

	human max = arr[0];
	human min = arr[0];

	for (int i{ 1 }; i < count; i++) {

		if (arr[i].year == max.year) {
			if (arr[i].month < max.month)
				max = arr[i];
			else if (arr[i].month == max.month) {
				if (arr[i].day < max.day)
					max = arr[i];
			}
		}
		else if (arr[i].year < max.year) {
			max = arr[i];
		}


		if (arr[i].year == min.year) {
			if (arr[i].month > max.month)
				min = arr[i];
			else if (arr[i].month == min.month) {
				if (arr[i].day > min.day)
					min = arr[i];
			}
		}
		else if (arr[i].year > min.year) {
			min = arr[i];
		}

	}


	cout << min.name << "\n"
		<< max.name;




	return 0;
}