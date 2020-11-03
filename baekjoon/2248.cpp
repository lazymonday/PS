#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6;
const int INF = 1e9;
typedef long long ll;

int n, m;
ll k;
ll dp[32][32];
string ans;

void solve(int num, int m, ll k) {

    if (num == 0) return;
    if (m == 0) {
        for (int i = 0; i < num; ++i)
        {
            ans += '0';
        }
        return;
    }

    ll skip = 0;
    for (int i = 0; i <= m; ++i)
    {
        skip += dp[num - 1][i];
    }

    if (skip >= k) {
        ans += '0';
        solve(num - 1, m, k);
    } else {
        ans += '1';
        solve(num - 1, m - 1, k - skip);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;

    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        dp[i][0] = 1;
        dp[i][i] = 1;
    }

    for (int i = 2; i <= n; ++i)
    {
        for (int j = 1; j < i; ++j)
        {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    solve(n, m, k);
    cout << ans;

    return 0;
}
