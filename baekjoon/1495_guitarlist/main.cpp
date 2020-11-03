#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 100;
int dt[MAX];
int n, s, m;
int dp[MAX + 1][1000 + 1];

int solve(int played, int currentVol) {
    if (currentVol > m || currentVol < 0) {
        return -2;
    }

    if (played >= n) {
        return currentVol;
    }

    auto &ret = dp[played][currentVol];
    if (ret != -1) {
        return ret;
    }

    ret = max(solve(played + 1, currentVol + dt[played]), solve(played + 1, currentVol - dt[played]));
    return ret;
}

int solve_iterative() {
    int cache[MAX + 1][1000 + 1];
    memset(cache, 0, sizeof cache);

    cache[0][s] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (cache[i][j] == 0) {
                continue;
            }

            if (j + dt[i] <= m) {
                cache[i + 1][j + dt[i]] = 1;
            }

            if (j - dt[i] >= 0) {
                cache[i + 1][j - dt[i]] = 1;
            }
        }
    }

    int answer = -1;
    for (int k = m; k >= 0; --k) {
        if (cache[n][k]) {
            answer = k;
            break;
        }
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n >> s >> m;
    for (int i = 0; i < n; ++i) {
        cin >> dt[i];
    }

    int ret = solve(0, s);
    cout << (ret == -2 ? -1 : ret) << "\n";
    cout << solve_iterative() << "\n";

    return 0;
}
