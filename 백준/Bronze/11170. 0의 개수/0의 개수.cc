#include<iostream>
#include<string>
using namespace std;


int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);



	int count;
	int N, M;
	int result;
	string s;
	cin >> count;
	for (int i{ 0 }; i < count; i++) {
		cin >> N >> M;
		result = 0;
		for (int i{ N }; i <= M; i++) {
			s = to_string(i);
			for (int k{ 0 }; k < s.length(); k++) {
				if (s[k] == '0') {
					result++;
				}
			}
		}
		cout << result << "\n";


	}

	return 0;
}