class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int threshold = nums.size() / 3.0 + 1; // needs more than threshold
        unordered_map<int, int> cnt;
        vector<int> ans;
        for(auto x : nums) {
            if(++cnt[x] == threshold) {
                ans.push_back(x);
            }
        }
        
        return ans;
    }
};