#include <bits/stdc++.h>
using namespace std;

const int maxM = 54;
const int maxN = 54;
int xLen, yLen, T, K;
bool visited[maxN][maxM];
int dx[] = { -1,1,0,0 };
int dy[] = { 0, 0, 1,-1 };

void DFS(int y, int x) {

    for (int k = 0; k < 4; k++) {
        int ny = y + dy[k];
        int nx = x + dx[k];
        if (ny < 0 || nx < 0 || ny >= yLen || nx >= xLen || visited[ny][nx]) continue;
            
        visited[ny][nx] = true;
        DFS(ny, nx);
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  
  
    cin >> T;

    while (T--) {
        memset(visited, true, sizeof(visited));
        int rnt = 0;
        cin >> xLen >> yLen >> K;
        
        int y, x;
        for (int k = 0; k < K; k++) {
            cin >> x >> y;
            visited[y][x] = false;
        }


        for (int y = 0; y < yLen; y++) {
            for (int x = 0; x < xLen; x++) {
                if (visited[y][x] == false) {
                    rnt++;
                    visited[y][x] == true;
                    DFS(y, x);
                }
            }
        }
        cout << rnt << "\n";
    }

    return 0;
}