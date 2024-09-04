#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxN = 1004;
int N, K, R, G, B;
int arr[maxN][3];
int costArr[maxN][3];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> costArr[i][0] >> costArr[i][1] >> costArr[i][2];
    }

    //첫 요소 삽입
    arr[0][0] = costArr[0][0];
    arr[0][1] = costArr[0][1];
    arr[0][2] = costArr[0][2];

    for (int i = 1; i < N; i++) {
        arr[i][0] = min(arr[i - 1][1], arr[i - 1][2]) + costArr[i][0];
        arr[i][1] = min(arr[i - 1][0], arr[i - 1][2]) + costArr[i][1];
        arr[i][2] = min(arr[i - 1][0], arr[i - 1][1]) + costArr[i][2];
    }

    int minResult = min(arr[N - 1][0], arr[N - 1][1]);
    minResult = min(minResult, arr[N - 1][2]);

    cout << minResult;

    return 0;
}