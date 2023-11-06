#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, M;
ll arr[300004];

bool check(ll mid) {
    ll count = 1;
    ll sum = mid;
    for (int i = 0; i < N; i++) {
        if (sum - arr[i] >=0) {
            sum -= arr[i];
        }
        else {
            count++;
            sum = mid;
            sum -= arr[i];
            if (sum < 0) return false;
        }
    }
    return M>=count;
}


int main() {
    cin >> N >> M;
    ll l = 1, r = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        r+=arr[i];
    }

    ll minResult = numeric_limits<ll>::max();
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
