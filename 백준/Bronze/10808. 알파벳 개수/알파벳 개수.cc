#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll arr[30];

int main()
{
    string s;
    cin >> s;
    for (char c : s)
    {
        arr[(int)c - 97]++;
    }

    for (ll i = 0; i < 26; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}