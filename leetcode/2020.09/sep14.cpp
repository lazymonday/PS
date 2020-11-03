class Solution {
public:

    int dp[101];

    int rob(vector<int>& nums) {

        if(nums.size() <= 0) return 0;
        
        memset(dp, 0, sizeof dp);
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (i == 1) {
                dp[i] = max(nums[1], dp[0]);
                continue;
            }

            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[nums.size() - 1];
    }
};