#include<iostream>
#include<vector>
#include<queue>
#define maxNum 50003
using namespace std;


// id1 => 노드, id2 => 연결된 자식 => id1의 vector에는 자식 노드가 담겨있다.
vector<int>adj[maxNum];
// idx = 노드 => 노드의 깊이를 구했는지 체크하는 배열
bool visit[maxNum];
// idx = 노드 => idx의 깊이를 알려주는 배열
int depth[maxNum];
// idx = 노드 => idx의 부모를 알려주는 배열
int parents[maxNum];
int N, M;


void DFS(int node, int dep) {
    visit[node] = true;
    depth[node] = dep;
    for (int i = 0; i < adj[node].size(); i++) {
        int nextNode = adj[node][i];
        if (visit[nextNode]) continue;
        parents[nextNode] = node;
        DFS(nextNode, dep + 1);
    }
}


int LCA(int node1, int node2) {
    if (node1 == node2) return node1;
    
    else if (depth[node1] == depth[node2]) {
        return LCA(parents[node1], parents[node2]);
    }
    else if (depth[node1] > depth[node2]) {
        return LCA(parents[node1], node2);
    }
    else{
        return LCA(node1, parents[node2]);
    }
}

int main() {
    int node1, node2;
    cin >> N;
    N--;
    while (N--) {
        cin >> node1 >> node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }

    DFS(1, 0);

    cin >> M;
    while (M--) {
        cin >> node1 >> node2;
        cout << LCA(node1, node2) << '\n';
    }    
    return 0;
}
