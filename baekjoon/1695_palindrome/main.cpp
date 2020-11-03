#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 1e9;
const int MAX = 5000;
int nums[MAX + 1];
int dp[MAX + 1][MAX + 1];
int n;

int solve(int left, int right) {
    if (left >= right) {
        return 0;
    }

    auto &ret = dp[left][right];
    if (ret != -1) {
        return ret;
    }

    ret = INF;

    if (nums[left] == nums[right]) {
        ret = min(ret, solve(left + 1, right - 1));
    } else {
        ret = min(solve(left + 1, right), solve(left, right - 1)) + 1;
    }

    return ret;
}

int solve_iterative() {
    for (int i = 1; i <= n; ++i) {
        for (int j = i - 1; j > 0; --j) {
            if (nums[i] == nums[j]) {
                dp[j][i] = dp[j + 1][i - 1];
            } else {
                dp[j][i] = min(dp[j][i - 1], dp[j + 1][i]) + 1;
            }
        }
    }

    return dp[1][n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int k = 1; k <= n; ++k) {
        cin >> nums[k];
    }

//    memset(dp, -1, sizeof dp);
//    cout << solve(1, n);
    cout << solve_iterative();
    return 0;
}
