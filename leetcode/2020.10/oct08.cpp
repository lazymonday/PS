class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size();
        
        while(lo < hi) {
            int x = lo + (hi-lo) / 2;
            if(nums[x] < target) {
                lo = x + 1;
            } else {
                hi = x;
            }
        }
        
        if(nums[lo] == target) {
            return lo;
        } 
        
        return -1;
    }
};