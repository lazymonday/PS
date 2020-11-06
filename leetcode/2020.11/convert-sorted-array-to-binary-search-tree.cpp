class Solution {
public:
    TreeNode* buildTree(vector<int>& nums, int lo, int hi) {
        if (lo >= hi) return 0;
        int x = lo + (hi - lo) / 2;

        auto ret = new TreeNode(nums[x]);
        ret->left = buildTree(nums, lo, x);
        ret->right = buildTree(nums, x + 1, hi);

        return ret;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        return buildTree(nums, 0, nums.size());
    }
};