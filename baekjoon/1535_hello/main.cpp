#include <iostream>
#include <cstring>

using namespace std;

const int INF = 1e9;
const int MAX = 20;
int n;
int happy[MAX + 1];
int cost[MAX + 1];
int dp[MAX + 2][102];

void solve_iterative() {
    for (int i = 1; i <= n; ++i) {   // member
        for (int j = 0; j <= 99; ++j) {   // hp를 어디까지 썼는가?
            dp[i][j] = dp[i - 1][j];
            if (j >= cost[i]) {
                dp[i][j] = max(dp[i - 1][j - cost[i]] + happy[i], dp[i][j]);
            }
        }
    }

    cout << dp[n][99];
}

int solve(int member, int remainHp) {
    if (member == 0) {
        return 0;
    }

    auto &ret = dp[member][remainHp];
    if (ret != -1) {
        return ret;
    }

    ret = solve(member - 1, remainHp);
    if (remainHp > cost[member]) {
        ret = max(ret, solve(member - 1, remainHp - cost[member]) + happy[member]);
    }
    return ret;
}


int main() {

    cin >> n;

    for (int k = 1; k <= n; ++k) {
        cin >> cost[k];
    }

    for (int k = 1; k <= n; ++k) {
        cin >> happy[k];
    }

    //memset(dp, -1, sizeof dp);
    //cout << solve(n, 100) << "\n";
    solve_iterative();

    return 0;
}
