#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e4;
int dp[MAX][MAX];

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int sz = prices.size();
        if (sz <= 1 || k <= 0) return 0;

        if (k * 2 >= sz) {
            int ret = 0;
            for (int i = 1; i < sz; ++i) {
                ret += max(0, prices[i] - prices[i - 1]);
            }

            return ret;
        }

        int dp[k + 1][sz];
        memset(dp, 0, sizeof dp);

        for (int i = 1; i <= k; ++i) {
            int maxDiff = -prices[0];
            for (int j = 1; j < sz; ++j) {
                dp[i][j] = max({dp[i][j - 1], maxDiff + prices[j]});
                maxDiff = max(maxDiff, dp[i - 1][j - 1] - prices[j]);
            }
        }

        return dp[k][sz - 1];
    }
};

int main() {

    int n = 1000;
    Solution s[n];
    vector<int> nums({3, 2, 6, 5, 0, 3});
    // vector<int> nums({2,4,1});
    cout << s[0].maxProfit(2, nums);
}