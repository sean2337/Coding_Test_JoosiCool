#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string s;
    cin >> s;
    string r = s;
    reverse(s.begin(), s.end());
    if (r == s)
        cout << 1;
    else
        cout << 0;

    return 0;
}