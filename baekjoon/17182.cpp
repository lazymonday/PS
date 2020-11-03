#include <bits/stdc++.h>

using namespace std;

const int MAX = 10;
const int INF = 1e9;
typedef long long ll;

int n, s;
int adj[MAX + 1][MAX + 1];
int dp[10][1 << 10];

void floyd() {
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == j) continue;
                if (adj[i][j] > adj[i][k] + adj[k][j]) {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }
}

int solve(int from, int visited) {
    if (visited == (1 << n) - 1) return 0;

    auto& ret = dp[from][visited];
    if (ret != -1) return ret;
    ret = INF;
    for (int i = 0; i < n; ++i)
    {
        if (visited & (1 << i)) continue;
        ret = min(ret, solve(i, visited | (1 << i)) + adj[from][i]);
    }

    return ret;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> s;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> adj[i][j];
        }
    }

    floyd();

    memset(dp, -1, sizeof dp);
    cout << solve(s, 1 << s);
    return 0;
}
