#include <iostream>
#include <algorithm>

using namespace std;

int n;
int nums[201];
int dp[201];

int main() {
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
    }

    int ans = 0;
    for (int j = 1; j <= n; ++j) {
        int here = 0;
        for (int i = 1; i <= j; ++i) {
            if(nums[j] > nums[i]) {
                here = max(here, dp[i]);
            }
        }

        dp[j] = here + 1;
        ans = max(ans, dp[j]);
    }

    cout << n - ans;

    return 0;
}
