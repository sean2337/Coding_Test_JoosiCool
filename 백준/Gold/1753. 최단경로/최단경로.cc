#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pairll;
const ll maxSize = 1e18 + 4;
const ll INF = 1e18;
ll N, K, M, T, V, E, num, a, b, c;
const ll maxN = 20004;
ll dis[maxN];
vector<pairll> adj[20004];
priority_queue < pairll, vector<pairll>, greater<pairll>> que;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  
    cin >> V >> E >> K;
    for (ll i = 0; i < E; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({ c,b });
    }

    fill(dis, dis + maxN, INF);
    dis[K] = 0;
    que.push({ 0, K });

    while (que.size()) {
        ll here = que.top().second;
        ll here_dist = que.top().first;
        que.pop();

        if (dis[here] != here_dist) continue;
        for (pairll _there : adj[here]) {
            ll there = _there.second;
            ll there_dist = _there.first;

            if (dis[there] > dis[here] + there_dist) {
                dis[there] = dis[here] + there_dist;
                que.push({ dis[there], there });
            }
        }
    }
   
    for (ll i = 1; i <= V; i++) {
        if (dis[i] == INF) {
            cout << "INF" << '\n';
        }
        else {
            cout << dis[i] << "\n";
        }
    }

    return 0;
}