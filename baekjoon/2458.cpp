#include <bits/stdc++.h>

using namespace std;

const int MAX = 500;
const int INF = 2e9;
typedef long long ll;


int n, m;
int adj[MAX + 1][MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u - 1][v - 1] = 1;
    }

    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                adj[i][j] |= adj[i][k] & adj[k][j];
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int cnt = 0;
        for (int j = 0; j < n; ++j)
        {
            if (i == j) continue;
            cnt += adj[i][j] | adj[j][i];
        }
        if (cnt == n - 1) ++ans;
    }

    cout << ans;

    return 0;
}
