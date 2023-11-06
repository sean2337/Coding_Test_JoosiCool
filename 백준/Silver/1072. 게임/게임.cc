#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll X, Y;
ll basic;


ll getWin(ll win, ll game) {
    return 100 * win / game;
}


int main() {
    cin >> X >> Y;  
    basic = getWin(Y, X);
    ll l = 1, r = X, mid;
    ll rnt = -1;
    while (l <= r) {
        mid = (l + r) / 2;
        if (basic != getWin(mid+Y,X+mid)) {
            r = mid - 1;
            rnt = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << rnt;

    
    return 0;
}
