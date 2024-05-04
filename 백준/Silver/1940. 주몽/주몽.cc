#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, M;
string s;
ll arr[20000];
ll rnt;
int main()
{
    cin >> N >> M;
    for (ll i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    ll l = 0, r = N - 1;
    while (l < r)
    {
        if (arr[l] + arr[r] == M)
        {
            rnt++;
            l++;
            r--;
        }
        else if (arr[l] + arr[r] < M)
        {
            l++;
        }
        else
        {
            r--;
        }
    }
    cout << rnt;

    return 0;
}