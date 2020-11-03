#include <bits/stdc++.h>

using namespace std;

const int MAX = 400;
const int INF = 1e9;
typedef long long ll;

int n, m;

bool adj[MAX + 1][MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v;
        adj[u][v] = true;
    }

    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                adj[i][j] |= (adj[i][k] & adj[k][j]);
            }
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        cin >> u >> v;
        if (adj[u][v]) {
            cout << -1 << "\n";
        } else if (adj[v][u]) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }

    return 0;
}
