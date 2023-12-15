#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
typedef long long ll;

map<string, string>mp;


int main() {

	mp["A+"] = "4.3"; mp["A0"] = "4.0"; mp["A-"] = "3.7";
	mp["B+"] = "3.3"; mp["B0"] = "3.0"; mp["B-"] = "2.7";
	mp["C+"] = "2.3"; mp["C0"] = "2.0"; mp["C-"] = "1.7";
	mp["D+"] = "1.3"; mp["D0"] = "1.0"; mp["D-"] = "0.7";
	mp["F"] = "0.0";

	string s;
	cin >> s;
	cout << mp[s];
}