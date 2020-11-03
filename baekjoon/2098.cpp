#include <bits/stdc++.h>

using namespace std;

const int MAX = 16;
const int INF = 1e9;
typedef long long ll;


int a[MAX + 1][MAX + 1];
int n;
ll dp[MAX + 1][1 << 16];

bool allVisited(unsigned int visit) {
    return __builtin_popcount(visit) == n;
}


ll solve(int start, unsigned int visit) {

    visit |= (1 << start);

    if (allVisited(visit)) {
        visit &= ~(1 << start);
        if (a[start][0] == 0) return INF;
        return a[start][0];
    }

    auto& ret = dp[start][visit];
    if (ret != -1) {
        return dp[start][visit];
    }

    ret = INF;
    for (int i = 0; i < n; ++i)
    {
        if ((visit & (1 << i)) != 0 || a[start][i] == 0) continue;
        ret = min(ret, solve(i, visit) + a[start][i]);

    }

    visit &= ~(1 << start);
    return ret;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> a[i][j];
        }
    }

    memset(dp, -1, sizeof dp);
    cout << solve(0, 0);

    return 0;
}
