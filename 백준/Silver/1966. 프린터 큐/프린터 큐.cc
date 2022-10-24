#include<iostream>
#include<queue>
using namespace std;

queue<int>que;

int main() {
	int count;
	cin >> count;
	int resultCount;
	int n, m;
	int iptNum;


	for (int i{ 0 }; i < count; i++)
	{
		resultCount = 0;
		cin >> n >> m;
		
		queue<pair<int, int>>q;
		priority_queue<int>pq;
		for (int j{ 0 }; j < n; j++)
		{
			cin >> iptNum;
			q.push({ j,iptNum });
			pq.push(iptNum);
		}

		while (!q.empty()) {
			int index = q.front().first;
			int value = q.front().second;
			q.pop();

			if (pq.top() == value) {
				pq.pop();
				++resultCount;
				if (index == m) {
					cout << resultCount << "\n";
					break;
				}
			}
			else {
				q.push({ index,value });
			}

		}

	}


	return 0;
}