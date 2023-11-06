#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll M, N;
ll arr[10004];

bool check(ll mid) {
    ll temp = M;
    for (ll i = 0; i < M; i++) {
        temp += mid / arr[i];
    }
    return N <= temp;
}


int main() {
    
    cin >> N >> M;
    for (ll i = 0; i < M; i++) {
        cin >> arr[i];
    }
    if (N <= M) {
        cout << N;
        return 0;
    }

    ll l = 0, r = 60000000004, mid;
    ll rnt = 0;

    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            r = mid - 1;
            rnt = mid;
        }
        else {
            l = mid + 1;
        }
    }

    ll temp = M;
    for (ll i = 0; i < M; i++) temp += ((rnt - 1) / arr[i]);

    for (ll i = 0; i < M; i++) {
        if (rnt % arr[i] == 0) temp++;
        if (temp == N) {
            cout << i + 1;
            return 0;
        }
    }


    return 0;
}
