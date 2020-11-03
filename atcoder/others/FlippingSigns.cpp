#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
int n;
const int MAX = 1e5;

ll dp[MAX][2];

ll solve(vector<ll> &nums) {

    dp[0][0] = nums[0] + nums[1];
    dp[0][1] = -nums[0] - nums[1];

    for (int i = 1; i < n - 1; ++i) {
        dp[i][0] = max(dp[i - 1][0] + nums[i + 1], dp[i - 1][1] + nums[i + 1]);
        dp[i][1] = max(dp[i - 1][0] - (2 * nums[i]) - nums[i + 1],
                       dp[i - 1][1] + (2 * nums[i]) - nums[i + 1]);
    }

    return max(dp[n - 2][0], dp[n - 2][1]);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    vector<ll> nums(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    ll ret = solve(nums);
    cout << ret << endl;

    return 0;
}
