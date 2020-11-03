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

        vector<int> buy(k + 1, -1e9);
        vector<int> sell(k + 1, 0);

        for (int i = 0; i < sz; ++i) {
            for (int j = 1; j <= k; ++j) {
                buy[j] = max(buy[j], sell[j - 1] - prices[i]);
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }

        return sell[k];
    }
};

int main() {

    int n = 1000;
    Solution s[n];
    vector<int> nums({3, 2, 6, 5, 0, 3});
    // vector<int> nums({2,4,1});
    cout << s[0].maxProfit(2, nums);
}