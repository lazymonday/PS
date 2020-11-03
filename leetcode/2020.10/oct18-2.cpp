#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e4;
int dp[MAX][MAX][2];

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int sz = prices.size();
        if (sz <= 1 || k <= 0) return 0;

        if (k * 2 > sz) {
            int ret = 0;
            for (int i = 1; i < sz; ++i) {
                ret += max(0, prices[i] - prices[i - 1]);
            }

            return ret;
        }

        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j < k + 1; ++j) {
                dp[i][j][0] = dp[i][j][1] = -1e9;
            }
        }

        dp[0][0][0] = 0;
        dp[0][0][1] = -prices[0];

        for (int i = 1; i < sz; ++i) {
            for (int j = 0; j < k + 1; ++j) {
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                if (j > 0)
                    dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            }
        }

        int ans = 0;
        for(int i = 0; i < k+1; ++i) {
            ans = max(ans, dp[sz-1][i][0]);
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums({3, 2, 6, 5, 0, 3});
    // vector<int> nums({2,4,1});
    cout << s.maxProfit(2, nums);
}