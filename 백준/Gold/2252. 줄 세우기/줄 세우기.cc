#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include<queue>
using namespace std;

const int maxV = 32010;
const int maxE = 100010;
int V, E, A, B, C;

int inDegree[maxV];
vector<vector<int>>graph(maxE);

void topology_sort() {
    queue<int>que;
    for (int i = 1; i <= V; i++) {
        if (inDegree[i] == 0) que.push(i);
    }

    for (int rep = 0; rep < V; rep++) {
        int from = que.front();
        cout << from << " ";
        que.pop();
        for (int i = 0; i < graph[from].size(); i++) {
            int to = graph[from][i];
            inDegree[to]--;
            if (inDegree[to] == 0) que.push(to);
        }

    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;
  
    for (int i = 0; i < E; i++) {
        cin >> A >> B;
        graph[A].push_back(B);
        inDegree[B]++;
    }
    topology_sort();
    return 0;
}