#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int MAX = 1e3;
const int INF = 2e9;
typedef long long ll;

pair<int, int> adj[MAX + 1];
bool visited[MAX + 1];
int matched[MAX + 1];

bool dfs(int u) {

    if (visited[u]) return false;
    visited[u] = true;

    for (int v = adj[u].first; v <= adj[u].second; ++v)
    {
        if (matched[v] == -1 || dfs(matched[v])) {
            matched[v] = u;
            return true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        memset(matched, -1, sizeof matched);

        for (int i = 0; i < m; ++i)
            cin >> adj[i].first >> adj[i].second;

        int flow = 0;
        for (int i = 0; i < m; ++i)
        {
            memset(visited, false, sizeof visited);
            if (dfs(i)) {
                ++flow;
            }
        }

        cout << flow << "\n";
    }

    return 0;
}
