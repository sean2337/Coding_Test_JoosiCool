#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, M;
string s;

int main()
{
    while (cin >> N)
    {
        ll num = 1;
        ll count = 1;
        while (true)
        {
            if (num % N == 0)
                break;
            num %= N;
            count++;
            num = num * 10 + 1;
        }
        cout << count << '\n';
    }
    return 0;
}