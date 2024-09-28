#include <bits/stdc++.h>
using namespace std;

const int maxN = 100;
const int maxIdx = 9;
const int mod = 1e9;
int N;

// first: stage 단계, second: 위치
int dp[maxN][maxIdx + 1];
int dI[] = { -1, 1 };

int solution(int stage, int idx) {
    if (stage < 0) return 0;
    if (dp[stage][idx]) return dp[stage][idx];

    for (int k = 0; k < 2; k++) {
        int nextIdx = idx + dI[k];
        if (nextIdx < 0 || nextIdx > maxIdx) continue;
        dp[stage][idx] = (dp[stage][idx] + solution(stage - 1, nextIdx)) % mod; // 모듈러 연산 추가
    }
    return dp[stage][idx];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 1; i <= maxIdx; i++) { 
        dp[0][i] = 1;
    }

    cin >> N;
    N--;

    int result = 0;
    for (int i = 0; i <= maxIdx; i++) {
        result = (result + solution(N, i)) % mod; 
    }
    cout << result;

    return 0;
}