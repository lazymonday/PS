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
    unordered_map<TreeNode*, TreeNode*> par;
    unordered_map<TreeNode*, int[2]> dp;

    int ans = 0;

    void dfs(TreeNode* node, TreeNode* p) {
        if (node == 0) {
            return;
        }

        dp[node][0] = 0;
        dp[node][1] = node->val;

        dfs(node->left, node);
        dfs(node->right, node);

        if (p) {
            dp[p][0] = max(dp[p][0] + dp[node][1], dp[p][0] + dp[node][0]);
            dp[p][1] = max(dp[p][1], dp[p][1] + dp[node][0]);
        }
    }

    int rob(TreeNode* root) {
        dfs(root, 0);
        return max(dp[root][0], dp[root][1]);
    }
};