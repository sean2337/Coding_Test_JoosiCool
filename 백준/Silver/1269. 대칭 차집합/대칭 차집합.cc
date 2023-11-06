#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, M, num;
map<ll,ll>mp;

bool findNum(int value, vector<int>vec) {
    auto pos = lower_bound(vec.begin(), vec.end(), value);
    int idx = (int)(pos - vec.begin());
    if (idx >= vec.size() || idx < 0) return false;
    return vec[idx] == value;
}

int main() {

    cin >> N >> M;
    vector<int> vec1(N), vec2(M);
    for (int i = 0; i < N; i++) {
        cin >> num;
        mp[num]++;
    }
    for (int i = 0; i < M; i++) {
        cin >> num;
        mp[num]++;
    }

    int sum = 0;
    for (auto v : mp) {
        if (v.second == 1) {
            sum++;
        }
    }
    cout << sum;

    return 0;
}
