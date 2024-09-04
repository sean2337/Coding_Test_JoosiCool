#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxN = 504;
int N, K, xLen, yLen;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
bool visited[maxN][maxN];
int arr[maxN][maxN];
int maxRnt;

// DFS 함수 정의
void DFS(int sy, int sx, int cnt, int sum) {
    if (cnt == 4) {
        maxRnt = max(maxRnt, sum);
        return;
    }
    for (int k = 0; k < 4; k++) {
        int ny = sy + dy[k];
        int nx = sx + dx[k];

        if (ny < 0 || nx < 0 || ny >= yLen || nx >= xLen || visited[ny][nx]) continue;
        visited[ny][nx] = true;
        DFS(ny, nx, cnt + 1, sum + arr[ny][nx]);
        visited[ny][nx] = false;
    }
}

// 'ㅗ' 모양 검사 함수 정의
void checkShape(int y, int x) {
    // 가능한 'ㅗ' 모양을 직접 정의하여 체크
    // 'ㅗ', 'ㅜ', 'ㅏ', 'ㅓ' 모양들
    int uShapes[4][3][2] = {
        {{0, 1}, {0, -1}, {1, 0}},   // 'ㅗ' 모양
        {{0, 1}, {0, -1}, {-1, 0}},  // 'ㅜ' 모양
        {{1, 0}, {-1, 0}, {0, 1}},   // 'ㅏ' 모양
        {{1, 0}, {-1, 0}, {0, -1}}   // 'ㅓ' 모양
    };
    for (int i = 0; i < 4; i++) {
        int sum = arr[y][x]; // 시작점의 값
        bool valid = true;
        for (int j = 0; j < 3; j++) {
            int ny = y + uShapes[i][j][0];
            int nx = x + uShapes[i][j][1];
            if (ny < 0 || nx < 0 || ny >= yLen || nx >= xLen) {
                valid = false;
                break;
            }
            sum += arr[ny][nx];
        }
        if (valid) {
            maxRnt = max(maxRnt, sum);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> yLen >> xLen;
    for (int y = 0; y < yLen; y++) {
        for (int x = 0; x < xLen; x++) {
            cin >> arr[y][x];
        }
    }

    // 모든 위치에서 DFS 탐색 및 ㅗ 모양 확인
    for (int y = 0; y < yLen; y++) {
        for (int x = 0; x < xLen; x++) {
            memset(visited, false, sizeof(visited)); // 방문 초기화
            visited[y][x] = true;
            DFS(y, x, 1, arr[y][x]); // DFS로 나머지 모양 탐색
            checkShape(y, x);        // 'ㅗ' 모양 체크
        }
    }
    cout << maxRnt;
    return 0;
}