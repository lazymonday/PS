#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
const int MAX = 1e5 + 1;
const int INF = 1e9;

int dp[MAX];
int rdp[MAX];

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int solve(vector<int> &nums) {

    // dp[i] = gcd by ith
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i] = gcd(nums[i - 1], dp[i - 1]);
    }

    // rdp[i] = gcd by
    rdp[n] = 0;
    for (int i = n - 1; i >= 0; --i) {
        rdp[i] = gcd(nums[i], rdp[i + 1]);
    }

    int ret = -INF;
    for (int i = 0; i < n; ++i) {
        ret = max(ret, gcd(dp[i], rdp[i + 1]));
    }

    return ret;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    vector<int> nums(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int ret = solve(nums);
    cout << ret << endl;

    return 0;
}
