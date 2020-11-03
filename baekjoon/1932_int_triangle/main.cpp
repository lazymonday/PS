#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 501;
int tri[MAX][MAX];
int dp[MAX][MAX];
int D[MAX];
int n;

int solve2() {
    for (int r = 1; r <= n; ++r) {
        for (int c = r; c >= 1; --c) {
            D[c] = max(D[c], D[c - 1]) + tri[r][c];
        }
    }

    int ret = 0;
    for (int i = 1; i <= n; ++i) {
        ret = max(ret, D[i]);
    }

    return ret;
}

int solve() {

    for (int r = 1; r <= n; ++r) {
        for (int c = 1; c <= r; ++c) {
            dp[r][c] = max(dp[r - 1][c - 1], dp[r - 1][c]) + tri[r][c];
        }
    }

    int ret = 0;
    for (int i = 1; i <= n; ++i) {
        ret = max(ret, dp[n][i]);
    }

    return ret;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int r = 1; r <= n; ++r) {
        for (int c = 1; c <= r; ++c) {
            cin >> tri[r][c];
        }
    }

    cout << solve2() << "\n";

    return 0;
}
