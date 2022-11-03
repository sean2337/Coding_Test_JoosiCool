#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool bigCheck(string a, string b) {
	if (a > b)
		return true;
	else {
		return false;
	}
}

string nameArr[20];
string nameArr2[20];

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int count;
	cin >> count;
	
	string name;

	for (int i{ 0 }; i < count; i++)
	{
		cin >> name;
		nameArr[i] = name;
		nameArr2[i] = name;
	}

	sort(nameArr2, nameArr2 + count);
	
	for (int i{ 0 }; i < count; i++)
	{
		if (nameArr[i] != nameArr2[i])
		{
			break;
		}
		if (i == count - 1)
		{
			cout << "INCREASING";
			return 0;
		}
			
		
	}
	

	
	sort(nameArr2, nameArr2 + count, bigCheck);
	
	for (int i{ 0 }; i < count; i++)
	{
		if (nameArr[i] != nameArr2[i])
		{
			break;
		}
		if (i == count - 1)
		{
			cout << "DECREASING";
			return 0;
		}
			
		
	}

	cout << "NEITHER";


	return 0;
}