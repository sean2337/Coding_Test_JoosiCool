#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;



int main() {

	int count,clothesCount;
	cin >> count;
	string name, kind;
	while (count--) {
		//종류, count 수
		cin >> clothesCount;
		map<string, int>clothMap;

		int result{ 1 };
		for (int i{ 0 }; i < clothesCount; i++)
		{
			cin >> name >> kind;
			if (clothMap.find(kind) == clothMap.end()) {
				clothMap.insert({ kind, 1 });
			}
			else {
				clothMap[kind]++;
			}
		}

	

			for (auto i:clothMap)
			{
				result *= (1 + i.second);
			}

			result--;

			cout << result << "\n";
			clothMap.clear();
		
		
	}



	return 0;
}