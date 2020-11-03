#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 1e9;
const int MAX = 200;
int n, k;
int color[MAX + 1];
int dp[MAX + 1][MAX + 1];
int dp2[MAX + 1][MAX + 1];

int solve1() {
    for (int j = 1; j <= n; ++j) {
        for (int i = j - 1; i > 0; --i) {
            dp[i][j] = INF;
            for (int mid = i; mid < j; ++mid) {
                dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j] + (color[i] != color[mid + 1]));
            }
        }
    }

    return dp[1][n];
}

int solve2(int start, int end) {
    if (start == end) {
        return 0;
    }

    auto &ret = dp2[start][end];
    if (ret != -1) {
        return ret;
    }

    ret = INF;
    for (int mid = start; mid < end; ++mid) {
        ret = min(ret, solve2(start, mid) + solve2(mid + 1, end) + (color[start] != color[mid + 1]));
    }

    return ret;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> color[i];
    }

    memset(dp2, -1, sizeof dp2);

    cout << solve1() << "\n";
    cout << solve2(1, n) << "\n";

    return 0;
}
