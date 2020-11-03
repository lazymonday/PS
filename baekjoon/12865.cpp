#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5;
const int INF = 1e9;
typedef long long ll;

int n, k;
int dp[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    int weight, value;
    for (int i = 1; i <= n; ++i)
    {
        cin >> weight >> value;
        for (int j = k; j >= weight; --j)
        {
            dp[j] = max(dp[j], dp[j - weight] + value);
        }
    }

    cout << dp[k];

    return 0;
}
