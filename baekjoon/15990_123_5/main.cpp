#include <iostream>

using namespace std;

typedef long long ll;

ll divisor = 1000000009LL;
const ll MAX = 100001LL;
int n;

ll dp[MAX][4];

ll solve(int n, int last) {

    if (n == 0) {
        return 1;
    }

    if (n < 0) {
        return 0;
    }

    ll &ret = dp[n][last];
    if (ret != -1) {
        return ret;
    }

    ret = 0;
    if (last == 0) {
        ret = solve(n - 1, 1) + solve(n - 2, 2) + solve(n - 3, 3);
    } else if (last == 1) {
        ret = solve(n - 2, 2) + solve(n - 3, 3);
    } else if (last == 2) {
        ret = solve(n - 1, 1) + solve(n - 3, 3);
    } else if (last == 3) {
        ret = solve(n - 1, 1) + solve(n - 2, 2);
    }

    ret %= divisor;
    return ret;
}

void solve2() {

    dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;

    for (int i = 4; i < MAX; ++i) {
        dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % divisor;
        dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % divisor;
        dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % divisor;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int j = 0; j < MAX; ++j) {
        for (int i = 0; i < 4; ++i) {
            dp[j][i] = 0;   // -1 for solve1
        }
    }

    solve2();

    cin >> n;
    int q;
    for (int i = 0; i < n; ++i) {
        cin >> q;
        cout << (((dp[q][1] + dp[q][2]) % divisor) + dp[q][3]) % divisor << endl;
        //cout << solve(q, 0) << endl;
    }

    return 0;
}
