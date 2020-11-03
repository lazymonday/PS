#include <iostream>

using namespace std;

const int INF = 1e9;
const int MAX = 200;
int n, toClose;
int mu[MAX + 2][3];
int dp[MAX + 2][3][MAX + 2];
const int LEFT = 1;
const int RIGHT = 2;
const int OPEN = 0;

int solve_recursive(int row, int pre, int closed) {
    if (row == n) {
        if (closed == toClose) {
            return 0;
        }
        return -INF;
    }

    auto &ret = dp[row][pre][closed];
    if (ret != -1) {
        return ret;
    }

    ret = solve_recursive(row + 1, OPEN, closed) + mu[row][LEFT] + mu[row][RIGHT];
    if (pre == OPEN || pre == LEFT) {
        ret = max(ret, solve_recursive(row + 1, LEFT, closed + 1) + mu[row][RIGHT]);
    }
    if (pre == OPEN || pre == RIGHT) {
        ret = max(ret, solve_recursive(row + 1, RIGHT, closed + 1) + mu[row][LEFT]);
    }

    return ret;
}

int main2() {
    cin >> n >> toClose;

    for (int i = 0; i <= n; ++i) {
        cin >> mu[i][1] >> mu[i][2];
    }

    memset(dp, -1, sizeof dp);
    int ans = solve_recursive(0, OPEN, 0);
    ans = max(ans, solve_recursive(0, LEFT, 0));
    ans = max(ans, solve_recursive(0, RIGHT, 0));

    cout << ans;

    return 0;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> toClose;
    for (int i = 1; i <= n + 1; ++i) {
        cin >> mu[i][LEFT] >> mu[i][RIGHT];
    }

    for (int j = 1; j <= n; ++j) {
        for (int i = 0; i <= toClose; ++i) {
            if (j > i) {
                dp[j][OPEN][i] =
                        max(dp[j - 1][OPEN][i], max(dp[j - 1][LEFT][i], dp[j - 1][RIGHT][i])) + mu[j][LEFT] +
                        mu[j][RIGHT];
            }

            if (i > 0) {
                dp[j][LEFT][i] = max(dp[j - 1][LEFT][i - 1], dp[j - 1][OPEN][i - 1]) + mu[j][RIGHT];
                dp[j][RIGHT][i] = max(dp[j - 1][RIGHT][i - 1], dp[j - 1][OPEN][i - 1]) + mu[j][LEFT];
            }
        }
    }

    int ans = dp[n][OPEN][toClose];
    ans = max(ans, dp[n][LEFT][toClose]);
    ans = max(ans, dp[n][RIGHT][toClose]);

    cout << ans;

    return 0;
}