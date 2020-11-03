#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000;
const int PIECE_MAX = 1e6;
const int INF = 1e9;
typedef long long ll;

int k, m, n;
int pa[MAX + 1];
int pb[MAX + 1];

int dp1[PIECE_MAX + 1];
int dp2[PIECE_MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> k >> m >> n;
    for (int i = 1; i <= m; ++i)
    {
        cin >> pa[i];
        pa[i] += pa[i - 1];
    }

    for (int i = 1; i <= n; ++i)
    {
        cin >> pb[i];
        pb[i] += pb[i - 1];
    }

    dp1[0] = dp2[0] = 1;
    for (int i = m; i >= 1; --i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (i == j) continue;
            if (i > j) {
                dp1[pa[i] - pa[j]]++;
            } else {
                dp1[pa[m] - (pa[j] - pa[i])]++;
            }
        }
    }

    for (int i = n; i >= 1; --i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == j) continue;
            if (i > j) {
                dp2[pb[i] - pb[j]]++;
            } else {
                dp2[pb[n] - (pb[j] - pb[i])]++;
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i <= k; ++i)
    {
        ans += 1ll * dp1[i] * dp2[k - i];
    }

    cout << ans;

    return 0;
}
