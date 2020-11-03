#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int MAX = 101;
const int INF = 1e9;
int n, k;
int coin[MAX];
int dp[MAX][10001];
int D[10001];

int solve2() {

    for (int m = 1; m <= k; ++m) { D[m] = INF; }

    for (int i = 1; i <= n; ++i) {
        for (int j = coin[i]; j <= k; ++j) {
            D[j] = min(D[j], D[j - coin[i]] + 1);
        }
    }

    return D[k] == INF ? -1 : D[k];
}

int solve(int kind, int remain) {
    if (kind == 0) {
        return remain == 0 ? 0 : INF;
    }

    auto &ret = dp[kind][remain];
    if (ret != -1) {
        return ret;
    }

//    ret = solve(kind - 1, remain);
//    if (coin[kind] != 0) {
//        ret = min(ret, solve(kind - 1, remain % coin[kind]) + remain / coin[kind]);
//    }

    ret = solve(kind - 1, remain);
    if (remain >= coin[kind]) {
        ret = min(ret, solve(kind, remain - coin[kind]) + 1);
    }

    return ret;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

//    memset(dp, -1, sizeof dp);

    cin >> n >> k;

    for (int l = 1; l <= n; ++l) {
        cin >> coin[l];
    }

    //sort(coin + 1, coin + n + 1);

    //int ret = solve(n, k);
    //cout << (ret == INF ? -1 : ret) << "\n";

    cout << solve2() << "\n";

    return 0;
}
