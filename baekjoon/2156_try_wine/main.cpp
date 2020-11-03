#include <iostream>
#include <cstring>

using namespace std;

const int INF = 1e9;
const int MAX = 1e4;
int nums[MAX + 1];
int dp[MAX + 1][3];
int D[MAX + 1];
int n;

int solve(int remain, int drinks) {
    if (remain == 0) {
        return 0;
    }

    auto &ret = dp[remain][drinks];
    if (ret != -1) return ret;
    ret = -INF;
    if (drinks >= 2) {
        ret = max(ret, solve(remain - 1, 0));
    } else {
        ret = max(solve(remain - 1, drinks + 1) + nums[remain], solve(remain - 1, 0));
    }

    return ret;
}

int main2() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
    }

    memset(dp, -1, sizeof dp);
    cout << solve(n, 0);

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
    }

    D[1] = nums[1];
    for (int j = 2; j <= n; ++j) {
        if (j >= 3) {
            D[j] = max(D[j - 1], max(D[j - 2], D[j - 3] + nums[j - 1]) + nums[j]);
        } else {
            D[j] = D[j - 1] + nums[j];
        }
    }

    cout << D[n];
}