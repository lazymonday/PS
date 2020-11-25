/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == 0) return 0;

        int ans = 0;
        if (low <= root->val and root->val <= high) ans += root->val;
        if (low < root->val) ans += rangeSumBST(root->left, low, high);
        if (high > root->val) ans += rangeSumBST(root->right, low, high);

        return ans;
    }
};