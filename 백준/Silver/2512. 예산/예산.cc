#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>
#include<tuple>
#include <cstring>
using namespace std;
typedef long long ll;

ll N, num, totalMoney;
ll maxValue = -1;
vector<ll>vec;

bool check(ll mid)
{
    ll remainMoney = totalMoney;
    // 돌면서 체크
    for (ll n : vec) {
        remainMoney -= min(n, mid);
        if (remainMoney < 0) {
            return false;
        }
    }
    return true;
}

int main() {
    
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num;
        vec.push_back(num);
        maxValue = max(maxValue, num);
    }
    cin >> totalMoney;


    ll  l = 0, r = maxValue;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (check(mid)) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    cout << r;

    return 0;
}