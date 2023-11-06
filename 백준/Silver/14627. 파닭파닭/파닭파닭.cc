#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll S, C, num;
vector<ll>vec;

bool check(ll value) {
    ll sum = 0;
    for (ll i : vec) {
        sum += (i / value);
    }
    return sum >= C;
}
int main() {
    
    cin >> S >> C;
    ll totalSum = 0;
    for (int i = 0; i < S; i++) {
        cin >> num;
        totalSum += num;
        vec.push_back(num);
    }

    ll l = 1, r = 1e18, mid;
    ll rnt = 0;
    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            rnt = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    cout << totalSum - C * rnt;
    return 0;
}
