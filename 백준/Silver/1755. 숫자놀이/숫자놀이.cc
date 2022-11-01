#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int num1, num2;
string s;
string numArr[11] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
vector<pair<string, int>> ans;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> num1 >> num2;


	for (int i = num1; i <= num2; i++)
	{

		if (i >= 10)
		{
			s = numArr[i / 10] +" "+ numArr[i % 10];
			ans.push_back({ s,i });
		}

		else {
			s = numArr[i % 10];
			ans.push_back({ s,i });
		}

	}
	sort(ans.begin(), ans.end());


	for (int i{ 0 }; i < ans.size(); i++) {
		cout << ans[i].second << " ";
		if (i % 10 == 9)
			cout << "\n";
	}


	return 0;
}