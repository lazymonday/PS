#include <iostream>


using namespace std;
typedef long long ll;
const int MAX = 100;
int nums[MAX + 1];
int n;
ll dp[MAX + 1][21];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
    }

    dp[1][nums[1]] = 1;
    for (int j = 2; j < n; ++j) {
        for (int i = 0; i <= 20; ++i) {
            if (i - nums[j] >= 0) {
                dp[j][i] += dp[j - 1][i - nums[j]];
            }
            if (i + nums[j] <= 20) {
                dp[j][i] += dp[j - 1][i + nums[j]];
            }
        }
    }

    cout << dp[n - 1][nums[n]];

    return 0;
}
