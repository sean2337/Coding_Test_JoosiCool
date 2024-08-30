#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>
#include<tuple>
#include <cstring>
using namespace std;
typedef pair<int, int> pairInt;

const int maxN = 104;
const int maxM = 104;

int N, M, cx, cy, nx, ny;
string inputLine;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

int visited[maxN][maxM];
char arr[maxN][maxM];


bool isRorG(int y, int x) {
    return arr[y][x] == 'R' || arr[y][x] == 'G';
}


//caseIdx = 0 : 적록색약인 사람 || caseIdx = 0 : 적록색약 아닌 사람
void DFS(int y, int x, int caseIdx) {

    for (int k = 0; k < 4; k++) {
        int ny = y + dy[k];
        int nx = x + dx[k];
        if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited[ny][nx]) continue;
        if (caseIdx == 0) {
            // 둘중에 하나가 R,G라면 같은거 취급
            if (isRorG(y, x) != isRorG(ny, nx)) continue;
        }
        else {
            if(arr[y][x] != arr[ny][nx]) continue;
        }
        visited[ny][nx] = 1;
        DFS(ny, nx, caseIdx);
    }
}




int main() {
    
    cin >> N;
    for (int y = 0; y < N; y++) {
        cin >> inputLine;
        for (int x = 0; x < N; x++) {
            arr[y][x] = inputLine[x];
        }
    }

    int cnt1 = 0, cnt2 = 0;
    
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (!visited[y][x]) {
                cnt1++;
                visited[y][x] = 1;
                DFS(y, x, 0);
            }
        }
    }

    memset(visited, false, sizeof(visited));

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (!visited[y][x]) {
                cnt2++;
                visited[y][x] = 1;
                DFS(y, x, 1);
            }
        }
    }

    cout << cnt2 << " " << cnt1;

    return 0;
}