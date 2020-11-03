#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 1e9;
const int MAX = 1001;
int dp[MAX][3];
int cost[MAX][3];
int n;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    for (int j = 1; j <= n; ++j) {
        for (int k = 0; k < 3; ++k) {
            dp[j][k] = min(dp[j - 1][(k + 1) % 3], dp[j - 1][(k + 2) % 3]) + cost[j][k];
        }
    }

    int ret = INF;
    for (int l = 0; l < 3; ++l) {
        ret = min(ret, dp[n][l]);
    }

    cout << ret << "\n";

    return 0;
}
