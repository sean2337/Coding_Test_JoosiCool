#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>
#include<tuple>
#include <cstring>
#include <climits>
using namespace std;
typedef long long ll;

ll N, num;
vector<ll>vec;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num;
        vec.push_back(num);
    }
    sort(vec.begin(), vec.end());

    ll  l = 0, r = N - 1;
    ll minL = LLONG_MAX; 
    ll maxR = LLONG_MIN;
    ll result = LLONG_MAX;

    while (l < r) {
        ll sum = vec[l] + vec[r];

        if (result > abs(sum)) {
            result = abs(sum);
            minL = l; maxR = r;
        }
        if (sum == 0) break;

        if (sum > 0) {
            r--;
        }
        else {
            l++;
        }
    }

    cout << vec[minL] << " " << vec[maxR];

    return 0;
}