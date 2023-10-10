#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <set>
#include <sstream>
#include <limits>
#include <math.h>
using namespace std;
const int maxNum = numeric_limits<int>::max();

int minResult = numeric_limits<int>::max();

bool arr[34][34] = { {false} };

int dx[] = { 0, 1, -1 };
int xLen, lineCount, yLen;

// 사다리 타기가 괜찮은지 체크
bool check() {
    for (int x = 1; x <= xLen; x++) {
        int curX = x;
        int y = 1;
        for (int j = 1; j <= yLen; j++) {
            if (arr[j][curX - 1]) {
                curX--;
            }
            else if (arr[j][curX]) {
                curX++;
            }
        }
        if (curX != x) {
            return false;
        }
    }
    return true;
}

void DFS(int y, int lineCount) {
    if (lineCount > 3 || lineCount>=maxNum) {
        return;
    }
    if (check()) {
        minResult = min(minResult, lineCount);
    }

    for (int nextX = 1; nextX <= xLen; nextX++) {
        for (int nextY = y; nextY <= yLen; nextY++) {
            if (arr[nextY][nextX] || arr[nextY][nextX - 1] || arr[nextY][nextX + 1]) continue;
            arr[nextY][nextX] = true;
            // 라인을 그리고 시도
            DFS(nextY, lineCount + 1);
            arr[nextY][nextX] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> xLen >> lineCount >> yLen;
    int y, x;
    for (int i = 1; i <= lineCount; i++) {
        cin >> y >> x;
        arr[y][x] = true;
    }

   
    DFS(1, 0);
        
    
    if (minResult == maxNum) {
        cout << -1;
    }
    else {
        cout << minResult;
    }

    return 0;
}
