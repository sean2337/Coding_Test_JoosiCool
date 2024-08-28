#include <iostream>
#include <vector>
using namespace std;

const int maxN = 54;
const int maxM = 54;
int N, M, sy, sx, sDir;
// 북, 동, 남, 서 기준으로 설정
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int arr[maxN][maxM];
bool isCleanArr[maxN][maxM];

// 왼쪽으로 돌면서 갈 곳이 있는지 확인
int isNear(int y, int x, int dir) {
    for (int k = 0; k < 4; k++) {
        // 왼쪽 방향부터 검사
        int newDir = (dir + 3 - k) % 4;
        int ny = y + dx[newDir];
        int nx = x + dy[newDir];
        if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        // 청소할 수 있는 방향 반환
        if (arr[ny][nx] == 0 && !isCleanArr[ny][nx]) return newDir;
    }
    return -1;
}

int go(int y, int x, int dir) {
    int rnt = 0;
    while (true) {
        // 현재 위치 청소
        if (!isCleanArr[y][x]) {
            isCleanArr[y][x] = true;
            rnt++;
        }

        int goDir = isNear(y, x, dir);
        // 주변에 청소할 곳이 없으면 후진
        if (goDir == -1) {
            int backDir = (dir + 2) % 4;
            int backY = y + dx[backDir];
            int backX = x + dy[backDir];
            // 후진할 수 없으면 종료
            if (backY < 0 || backX < 0 || backY >= N || backX >= M || arr[backY][backX] == 1) return rnt;
            // 후진할 수 있으면 이동
            y = backY; x = backX;
        }
        // 청소할 곳이 있으면 그 방향으로 이동
        else {
            dir = goDir;
            y = y + dx[dir];
            x = x + dy[dir];
        }
    }
    return rnt;
}

int main() {
    cin >> N >> M;
    cin >> sy >> sx >> sDir;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    cout << go(sy, sx, sDir);

    return 0;
}