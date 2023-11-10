#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxNum = 39;
ll dp[maxNum];

int main() {
    dp[0] = 0;
    dp[1] = 5;
    dp[2] = 13;

    ll N, M;
    string s = "Messi Gimossi";

    cin >> M; M--;
    for (int i = 3; i <= maxNum; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + 1;
    }

    for (int i = maxNum; i >=2; i--) {
        if (dp[i] <= M) {
            M -= (dp[i] + 1);
        }
    }

    if (M == 5 || M == -1) {
        cout << "Messi Messi Gimossi";
    }
    else {
        cout << s[M];
    }

    return 0;
}
