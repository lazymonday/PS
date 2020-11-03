#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100;
const int INF = 2e9;
typedef long long ll;

int n, m;
vector<int> adj[MAX + 1];
int visited[MAX + 1];

int dfs(int u) {

    visited[u] = true;

    int ret = 1;
    for (auto& x : adj[u])
    {
        if (visited[x]) continue;
        ret += dfs(x);
    }

    return ret;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << dfs(1) - 1;

    return 0;
}
