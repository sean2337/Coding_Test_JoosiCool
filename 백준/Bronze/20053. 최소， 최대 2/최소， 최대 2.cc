#include <iostream>
#include <cstring>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int maxT = 10;
const int maxN = 1e6;
int T, N, num;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while (T--) {
        int maxRnt = -987654321;
        int minRnt = 987654321;

        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> num;
            maxRnt = max(maxRnt, num);
            minRnt = min(minRnt, num);
        }
        cout << minRnt << " " << maxRnt << '\n';
    }
    return 0;
}