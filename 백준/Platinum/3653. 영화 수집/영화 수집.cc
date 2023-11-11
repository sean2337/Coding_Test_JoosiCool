#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxNum = 200004;
ll arr[maxNum];
ll tree[maxNum];
ll T, N, M, num;
map<ll, ll> movieMap;


void update(ll idx, ll dif) {
    while (idx <= maxNum) {
        tree[idx] += dif;
        idx += (idx & -idx);
    }
}

ll sum(ll idx) {
    ll result = 0;
    while (idx > 0) {
        result += tree[idx];
        idx -= (idx & -idx);
    }
    return result;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> N >> M;

        memset(tree, 0, sizeof(tree));
        //fill(tree, tree + maxNum, 0);
        movieMap.clear();

        ll plusIdx = 100001;
        for (int i = 1; i <= N; i++) {
            update(i + plusIdx, 1);
            movieMap[i] = i + plusIdx;
        }
        for (int i = 0; i < M; i++) {
            cin >> num;
            ll idx = movieMap[num];
            cout << sum(idx) - 1 << ' ';
            update(idx, -1);
            update(--plusIdx, 1);
            movieMap[num] = plusIdx;
        }
        cout << '\n';
    }
    return 0;
}
