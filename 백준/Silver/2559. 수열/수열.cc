#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, M, num;
string s;
ll prefixSum[100004];

int main()
{
    cin >> N >> M;
    for (ll i = 1; i <= N; i++)
    {
        cin >> num;
        prefixSum[i] = prefixSum[i - 1] + num;
    }
    ll rnt = -10000000;
    for (ll i = 0; i <= N - M; i++)
    {
        rnt = max(rnt, prefixSum[i + M] - prefixSum[i]);
    }
    cout << rnt;

    return 0;
}