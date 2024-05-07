#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, M, T, K;
string s;
char arr[104][104];

ll solveDis(ll y, ll x)
{
    ll dis = 0;
    while (true)
    {
        if (arr[y][x] == 'c')
        {
            return dis;
        }
        x--;
        dis++;
        if (x < 0)
            return -1;
    }
}

int main()
{
    cin >> N >> M;
    for (ll i = 0; i < N; i++)
    {
        cin >> s;
        for (ll j = 0; j < M; j++)
        {
            arr[i][j] = s[j];
        }
    }

    for (ll i = 0; i < N; i++)
    {
        for (ll j = 0; j < M; j++)
        {
            cout << solveDis(i, j) << " ";
        }
        cout << '\n';
    }

    return 0;
}