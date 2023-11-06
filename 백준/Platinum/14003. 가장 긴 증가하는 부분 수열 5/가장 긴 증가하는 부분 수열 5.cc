#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll maxNum = 1000004;
ll N, len, num;
ll lists[maxNum];
pair<ll, ll> vec[1000004];
stack<ll>stk;
const int INF = 1e9 + 4;


int main() {
    fill(lists, lists + 1000004, INF);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num;
        auto pos = lower_bound(lists, lists + len, num);
        ll idx = (ll)(pos - lists);
        
        if (*pos == INF) len++;
        *pos = num;
        vec[i].first = idx;
        vec[i].second = num;
    }

    cout << len << '\n';

    for (int i = N - 1; i >= 0; i--) {
        if (len - 1 == vec[i].first) {
            stk.push(vec[i].second); len--;
        }
    }

    while (stk.size())
    {
        cout<<stk.top()<<" "; stk.pop();
    }

    return 0;
}