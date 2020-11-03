#include <bits/stdc++.h>

using namespace std;

const int MAX = 100;
const int INF = 1e9;
typedef long long ll;

bool adj[MAX + 1][MAX + 1];
int ans[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[v][u] = true;
    }

    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                adj[i][j] |= adj[i][k] & adj[k][j];
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        int ans = n - 1;
        for (int j = 1; j <= n; ++j)
        {
            if (i == j) continue;
            ans -= adj[i][j] || adj[j][i];
        }
        cout << ans << "\n";
    }

    return 0;
}
