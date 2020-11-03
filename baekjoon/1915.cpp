#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000;
const int INF = 2e9;
typedef long long ll;

int rmax, cmax;
char a[MAX + 1][MAX + 1];
int dp[MAX + 1][MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> rmax >> cmax;
    for (int i = 0; i < rmax; ++i)
    {
        cin >> a[i];
    }

    for (int i = 0; i < cmax; ++i)
    {
        for (int j = 0; j < rmax; ++j)
        {
            dp[j][i] = (a[j][i] == '1' ? 1 : 0);
        }
    }

    for (int i = 1; i < rmax; ++i)
    {
        for (int j = 1; j < cmax; ++j)
        {
            if (a[i][j] == '0') {
                dp[i][j] = 0;
            } else {
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]);
                dp[i][j] = min(dp[i][j], dp[i][j - 1]);
                dp[i][j] += 1;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < rmax; ++i)
    {
        ans = max(ans, *max_element(dp[i], dp[i] + cmax));
    }

    cout << ans * ans;

    return 0;
}
