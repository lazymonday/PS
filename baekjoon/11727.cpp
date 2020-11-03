#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e3;
const int INF = 2e9;
const int MOD = 1e4 + 7;
typedef long long ll;

int n;
int dp[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 3;
    for (int i = 3; i <= n; ++i)
    {
        dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % MOD;
    }

    cout << dp[n];

    return 0;
}
