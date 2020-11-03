#include <bits/stdc++.h>

using namespace std;

const int MAX = 5000;
const int INF = 2e9;
typedef long long ll;

int n, q;
vector<pair<int, int>> edge[MAX + 1];
bool visited[MAX + 1];
int rel[MAX + 1];

void dfs(int here, int minVal) {

    if (visited[here]) return;
    visited[here] = true;

    for (int i = 0; i < edge[here].size(); ++i)
    {
        int there = edge[here][i].first;
        if (visited[there]) continue;
        dfs(there, min(edge[here][i].second, minVal));
    }

    rel[here] = minVal;
}

int count(int v, int k) {

    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (v == i || rel[i] == INF) continue;
        if (rel[i] >= k) ans++;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;

    for (int i = 1; i < n; ++i)
    {
        int u, v, cost;
        cin >> u >> v >> cost;
        edge[u].push_back({v, cost});
        edge[v].push_back({u, cost});
    }

    int k, v;
    for (int i = 0; i < q; ++i)
    {
        cin >> k >> v;
        memset(visited, 0, sizeof visited);
        for (int i = 0; i <= n; ++i)
            rel[i] = INF;
        dfs(v, INF);
        cout << count(v, k) << "\n";
    }

    return 0;
}
