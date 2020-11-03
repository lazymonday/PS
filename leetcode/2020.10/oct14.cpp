class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() <= 1) return nums[0];
        
        int dp[105] = {0, };
        dp[0] = 0, dp[1] = nums[1]; // don't rob first
        for(int i = 2; i < nums.size(); ++i) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        
        int cand = dp[nums.size()-1];
        memset(dp, 0, sizeof dp);
        dp[0] = dp[1] = nums[0];    // rob first
        for(int i = 2; i < nums.size()-1; ++i) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        
        return max(cand, dp[nums.size()-2]);
    }
};