#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        int dp[n];
        int freq[n];
        memset(dp, 0, sizeof dp);
        memset(freq, 0, sizeof freq);

        for (int i = 0; i < n; ++i) {
            dp[i] = freq[i] = 1;
        }

        int ans = 0;
        for (int i = 1; i < n; ++i)
        {
            int cand = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        freq[i] = freq[j];
                    } else if (dp[i] == dp[j] + 1) {
                        freq[i] += freq[j];
                    }
                }
            }

            dp[i] = max(dp[i], cand);
            if (ans < dp[i]) {
                ans = dp[i];
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (ans == dp[i]) cnt += freq[i];
        }

        return cnt;
    }
};

int main() {
    Solution s;
    vector<int> a({1, 3, 5, 10, 2, 4, 7});
    // vector<int> a({1,1,1,2,2,2});
    cout << s.findNumberOfLIS(a);
    return 0;
}