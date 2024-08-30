#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <tuple>
#include <cstring>
#include <climits>
#include <cmath>
using namespace std;
typedef long long ll;

int arr[25][25];
int visited[25][25];
int num;

int howManyBingo(int y, int x) {

    int cnt = 0;
    bool flag;

    flag = true;
    for (int i = 0; i < 5; i++) {
        if (!visited[y][i]) {
            flag = false;
            break;
        }
    }
    if (flag) cnt++;

    flag = true;
    for (int i = 0; i < 5; i++) {
        if (!visited[i][x]) {
            flag = false;
            break;
        }
    }
    if (flag) cnt++;

    
    if (y == x) {  
        flag = true;
        for (int i = 0; i < 5; i++) {
            if (!visited[i][i]) {
                flag = false;
                break;
            }
        }
        if (flag) cnt++;
    }

    if (y + x == 4) {
        flag = true;
        for (int i = 0; i < 5; i++) {
            if (!visited[i][4 - i]) {
                flag = false;
                break;
            }
        }
        if (flag) cnt++;
    }

    return cnt;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            cin >> arr[y][x];
        }
    }
    int bingoCnt = 0;

    for (int i = 0; i < 25; i++) {
        cin >> num;
        for (int y = 0; y < 5; y++) {
            for (int x = 0; x < 5; x++) {
                if (arr[y][x] == num) {
                    visited[y][x] = 1;
                    bingoCnt += howManyBingo(y, x);
                    if (bingoCnt >= 3) {
                        cout << i + 1;
                        return 0;
                    }
                    y = 5; x = 5;
                }
            }
        }
    endLoop:;
    }

    return 0;
}