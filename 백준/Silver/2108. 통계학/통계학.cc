#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

bool comp(pair<int, int> p1, pair<int, int> p2) {
	if (p1.second == p2.second) {
		return p1.first < p2.first;
	}
	else {
		return p1.second > p2.second;
	}
}

int arr[500003];


int main() {

	int count;
	cin >> count;

	for (int i{ 0 }; i < count; i++) {
		cin >> arr[i];
	}

	double result1{0};
	double result2;
	double result3;
	double result4;

	//산술평균
	for (int i{ 0 }; i < count; i++) {
		result1 += arr[i];
	}
	result1 = floor(result1 / count+0.5);
	cout << result1 << "\n";


	//중앙값
	sort(arr, arr + count);
	result2 = arr[count / 2];
	cout << result2 << "\n";


	//최빈값
	vector < pair<int, int> > st;
	for (int i{ 0 }; i < count; i++) {
		if (st.empty())
		{
			st.push_back(pair<int, int>(arr[i], 1));
			continue;
		}

		if (st.back().first == arr[i]) {
			pair<int, int>tmp = st.back();
			tmp.second++;
			st.pop_back();
			st.push_back(tmp);
		}
		else
		{
			st.push_back(pair<int, int>(arr[i], 1));
		}
	}

	sort(st.begin(), st.end(), comp);

	if (st[0].second == st[1].second) {
		result3 = st[1].first;
	}
	else {
		result3 = st[0].first;
	}

	cout << result3 << "\n";

	//범위
	result4 = arr[count - 1]- arr[0];
	cout << result4;

}