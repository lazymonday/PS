#include <iostream>
#include <cstring>

using namespace std;

const int INF = 1e9;
const int MAX = 500;
int nums[MAX + 1];
int dp[MAX + 1][MAX + 1];
int psum[MAX + 1];
int mid[MAX + 1][MAX + 1];
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> nums[i];
            psum[i] = psum[i - 1] + nums[i];
            mid[i][i] = i;
        }

        for (int len = 1; len < n; ++len) {
            for (int i = 1; i + len <= n; ++i) {
                int j = i + len;
                dp[i][j] = INF;
                for (int k = mid[i][j - 1]; k <= mid[i + 1][j]; ++k) {
                    if (dp[i][j] > dp[i][k] + dp[k + 1][j] + psum[j] - psum[i - 1]) {
                        dp[i][j] = dp[i][k] + dp[k + 1][j] + psum[j] - psum[i - 1];
                        mid[i][j] = k;
                    }

                }
            }
        }

        cout << dp[1][n] << "\n";
    }

    return 0;
}


int main2() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> nums[i];
            psum[i] = psum[i - 1] + nums[i];
        }

        for (int len = 1; len < n; ++len) {
            for (int i = 1; i + len <= n; ++i) {
                int j = i + len;
                dp[i][j] = INF;
                for (int k = i; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + psum[j] - psum[i - 1]);

                }
            }
        }

        cout << dp[1][n] << "\n";
    }

    return 0;
}
