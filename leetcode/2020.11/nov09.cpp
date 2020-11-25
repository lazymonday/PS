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
    int dfs(TreeNode* node, int minval, int maxval) {
        if(node == 0) return maxval - minval;
        
        minval = min(node->val, minval);
        maxval = max(node->val, maxval);
        return max(dfs(node->left, minval, maxval), dfs(node->right, minval, maxval));
    }
    
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }
};