#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxNum = 1030;
ll tree[maxNum][maxNum];
ll arr[maxNum][maxNum];
ll N, M, x1, yy1, x2, y2, w, c;


void update(ll y, ll x, ll dif) {
    while (y <= N) {
        ll j = x;
        while (j <= N) {
            tree[y][j] += dif;
            j += (j & -j);
        }
        y += (y & -y);
    }
}

ll sumTree(ll y, ll x) {
    ll rnt = 0;
    while (y >0) {
        ll j = x;
        while (j > 0) {
            rnt += tree[y][j];
            j -= (j & -j);
        }
        y -= (y & -y);
    }
    return rnt;
}


int main() {

    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); 
    cout.tie(NULL);

    cin >> N >> M;
    for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j <= N; j++) {
            cin >> arr[i][j];
            update(i, j, arr[i][j]);
        }
    }

    for (int i = 0; i < M;i++) {
        cin >> w;
        if (w == 0) {
            int x, y;
            cin >> y >> x >> c;
            update(y, x, c - arr[y][x]);
            arr[y][x] = c;

        }
        else {
            cin >> yy1 >> x1 >> y2 >> x2;
            cout << sumTree(y2, x2) - sumTree(y2,x1-1) - sumTree(yy1-1, x2) + sumTree(yy1 - 1, x1 - 1) << '\n';
        }
    }

    return 0;
}
