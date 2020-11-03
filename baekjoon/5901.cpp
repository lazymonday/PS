#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e4;
const int INF = 1e9;
typedef long long ll;

int dist[5][MAX + 1];
int n, k, m;
int markets[5];
bool isMarket[MAX + 1];
map<int, int> marketTbl;
bool taken[5];
vector<pair<int, int>> edges[MAX + 1];

void dijkstra(int start) {

    priority_queue<pair<int, int>> pq;

    int mstart = markets[start];
    dist[start][mstart] = 0;
    pq.push({0, mstart});

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if (dist[start][here] < cost) continue;

        for (auto next : edges[here])
        {
            int nextCost = dist[start][here] + next.second;
            if (dist[start][next.first] > nextCost) {
                dist[start][next.first] = nextCost;
                pq.push({ -nextCost, next.first});
            }
        }
    }
}

int solve(int start, vector<int>& traversed, int distance) {

    int ret = INF;

    if (traversed.size() == k) {
        return distance + dist[marketTbl[traversed.back()]][start];
    }

    for (int i = 0; i < k; ++i)
    {
        if (taken[i]) continue;
        taken[i] = true;
        int extraDist = 0;
        if (traversed.size() == 0) {
            extraDist = dist[i][start];
        } else {
            extraDist += dist[marketTbl[traversed.back()]][markets[i]];
        }

        traversed.push_back(markets[i]);
        ret = min(ret, solve(start, traversed, distance + extraDist));
        traversed.pop_back();
        taken[i] = false;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i) {
        cin >> markets[i];
        isMarket[markets[i]] = true;
        marketTbl.insert({markets[i], i});
    }

    int u, v, c;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v >> c;
        edges[u].push_back({v, c});
        edges[v].push_back({u, c});
    }

    memset(dist, 0x3f, sizeof dist);
    for (int i = 0; i < k; ++i) dijkstra(i);

    int ans = INF;
    for (int i = 1; i <= n; ++i)
    {
        vector<int> traversed;
        if (isMarket[i]) continue;
        ans = min(ans, solve(i, traversed, 0));
    }

    cout << ans;
    return 0;
}
