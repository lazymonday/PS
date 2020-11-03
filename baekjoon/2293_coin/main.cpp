#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 100;
int n, k;
int coin[MAX + 1];
int dp[MAX + 1][10001];
int D[MAX + 1][10001];
int D1[10001];

int solve3() {

    D1[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = coin[i - 1]; j <= k; ++j) {
            D1[j] += D1[j - coin[i - 1]];
        }
    }

    return D1[k];
}

int solve2() {

    D[0][0] = 1;
    for (int i = 0; i < n; ++i) {       // kind
        for (int j = 0; j <= k; ++j) {   // target number
            int upper = ((k - j) / coin[i]);
            for (int l = 0; l <= upper; ++l) {
                D[i + 1][j + coin[i] * l] += D[i][j];
            }
        }
    }

    return D[n][k];
}

int solve(int kind, int remain) {
    if (remain == 0) {
        return 1;
    }

    if (kind == n || remain < 0) {
        return 0;
    }

    auto &ret = dp[kind][remain];
    if (ret != -1) {
        return ret;
    }

    ret = 0;
    int upper = remain / coin[kind];
    for (int i = 0; i <= upper; ++i) {
        ret += solve(kind + 1, remain - coin[kind] * i);
    }

    return ret;
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        cin >> coin[i];
    }

    cout << solve(0, k) << "\n";
    cout << solve2() << "\n";
    cout << solve3() << "\n";
    return 0;
}
