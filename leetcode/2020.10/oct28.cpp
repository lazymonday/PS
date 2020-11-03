class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() <= 0) return vector<string>();

        typedef long long ll;
        nums.push_back(nums.back());
        vector<string> ans;
        int begin = 0, end = 1;
        while (end < nums.size()) {
            bool add = false;
            if (nums[end] - nums[begin] * 1ll == end * 1ll - begin) {
                end++;
                if (end >= nums.size()) add = true;
            } else {
                add = true;
            }

            if (add) {
                if (begin + 1 == end) {
                    ans.push_back(to_string(nums[begin]));
                } else {
                    string cand = to_string(nums[begin]) + "->" + to_string(nums[end - 1]);
                    ans.push_back(cand);
                }
                begin = end;
                end = begin + 1;
            }
        }

        return ans;
    }
};