#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, M;
ll arr[300004];

bool check(ll mid) {
    ll num = 0;
    ll count = 1;
    for (int i = 0; i < N; i++) {
        if (mid >= num + arr[i]) {
            num += arr[i];
        }
        else {
            if (arr[i] > mid) {
                return false;
            }
            num = arr[i];
            count++;
        }
    }
    return M>=count;
}


int main() {
    cin >> N >> M;
    ll l = 1, r = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        r += arr[i];;
    }

    ll minResult = 987654321;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (check(mid)) {
            minResult = min(minResult, mid);
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << minResult;

    return 0;
}
