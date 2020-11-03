#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 32768;
int dp[MAX][200][4];
int dp2[MAX + 1][5];

void solve_dp() {
    dp2[0][0] = 1;
    for (int i = 1; i * i <= MAX; ++i) {
        for (int j = i * i; j <= MAX; ++j) {
            for (int k = 1; k <= 4; ++k) {
                dp2[j][k] += dp2[j - i * i][k - 1];
            }
        }
    }
}


int solve(int num, int pre, int remain) {

    if (remain < 0) {
        return 0;
    }

    if (num == 0 && remain >= 0) {
        return 1;
    }

    auto &ret = dp[num][pre][remain];
    if (ret != -1) {
        return ret;
    }

    ret = 0;
    for (int i = pre; i * i <= num; ++i) {
        ret += solve(num - i * i, i, remain - 1);
    }

    return ret;
}


int main() {

    memset(dp, -1, sizeof dp);
    solve_dp();
    int num;
    while (true) {
        cin >> num;
        if (num == 0) {
            break;
        }

        cout << solve(num, 1, 4) << "\n";
        cout << dp2[num][1] + dp2[num][2] + dp2[num][3] + dp2[num][4] << "\n";
    }

    return 0;
}
