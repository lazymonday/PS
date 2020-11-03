#include <bits/stdc++.h>

using namespace std;

const int Max = 1e4;
int dp[Max][Max];

class Solution {
public:

    int solve(vector<int>& prices, int start, int k) {
        if (start >= prices.size() || k <= 0) return 0;

        auto& ret = dp[start][k];
        if (ret != -1) return ret;

        ret = 0;
        int psum = 0;
        int minval = 0;
        for (int i = start; i < prices.size(); ++i) {
            psum += prices[i] - prices[i - 1];
            if (psum - minval > 0) {
                // cout << "start : " << i << ", K : " << k << ", psum : " << psum << ", min : " << minval << "\n";
                ret = max(ret, solve(prices, i + 1, k - 1) + psum - minval);

            }
            minval = min(psum, minval);
        }

        return ret;
    }

    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() <= 1 || k <= 0) return 0;

        int sz = prices.size();
        if (k * 2 > sz) {
            int ret = 0;
            for (int i = 1; i < sz; ++i) {
                ret += max(0, prices[i] - prices[i - 1]);
            }

            return ret;
        }

        memset(dp, -1, sizeof dp);
        return solve(prices, 1, k);
    }
};

int main() {
    Solution s;
    vector<int> nums({3, 2, 6, 5, 0, 3});
    // vector<int> nums({2,4,1});
    cout << s.maxProfit(2, nums);
}