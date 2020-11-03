#include <iostream>

using namespace std;

typedef long long ll;
const ll divisor = 1e9;
const int MAX = 100;
int n;
ll dp[MAX + 1][11][(1 << 10) + 1];

int main() {

    cin >> n;

    ll ans = 0;

    for (int k = 1; k < 10; ++k) {
        dp[1][k][1 << k] = 1;
    }

    for (int i = 2; i <= MAX; ++i) {    // 자리수
        for (int j = 0; j <= 9; ++j) {
            for (int k = 0; k < 1024; ++k) {
                if (j == 0) {
                    dp[i][j][k | (1 << j)] += dp[i - 1][j + 1][k] % divisor;
                } else if (j == 9) {
                    dp[i][j][k | (1 << j)] += dp[i - 1][j - 1][k] % divisor;
                } else {
                    dp[i][j][k | (1 << j)] +=
                            (dp[i - 1][j - 1][k] + dp[i - 1][j + 1][k]) % divisor;
                }
            }
        }
    }

    ans = 0;
    for (int l = 0; l < 10; ++l) {
        ans = (ans + dp[n][l][1023]) % divisor;
    }
    cout << ans << "\n";

    return 0;
}
