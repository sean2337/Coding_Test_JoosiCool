#include<iostream>
#include<string>
using namespace std;

int main() {

	string inName;
	double inNumber;
	string inGrade;
	double result{0};
	double sumNumber{0};

	for (int i{ 0 }; i < 20; i++)
	{
		cin >> inName>>inNumber>>inGrade;
		if (inGrade == "A+") {
			sumNumber += inNumber;
			result += (inNumber * 4.5);
		}
		else if (inGrade == "A0") {
			sumNumber += inNumber;
			result += (inNumber * 4.0);
		}
		else if (inGrade == "B+") {
			sumNumber += inNumber;
			result += (inNumber * 3.5);
		}
		else if (inGrade == "B0") {
			sumNumber += inNumber;
			result += (inNumber * 3.0);
		}
		else if (inGrade == "C+") {
			sumNumber += inNumber;
			result += (inNumber * 2.5);
		}
		else if (inGrade == "C0") {
			sumNumber += inNumber;
			result += (inNumber * 2.0);
		}
		else if (inGrade == "D+") {
			sumNumber += inNumber;
			result += (inNumber * 1.5);
		}
		else if (inGrade == "D0") {
			sumNumber += inNumber;
			result += (inNumber * 1.0);
		}
		else if (inGrade == "F") {
			sumNumber += inNumber;
			result += (inNumber * 0.0);
		}


	}

	result = result / sumNumber;
	cout << result;



	return 0;
}