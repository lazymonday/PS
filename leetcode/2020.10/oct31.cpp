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
    
    vector<pair<int, TreeNode*>> inorder;
    
    void dfs(TreeNode* root) {
        if(!root) return;
        
        dfs(root->left);
        inorder.push_back({root->val, root});
        dfs(root->right);
    }

    void recoverTree(TreeNode* root) {
        dfs(root);
        
        int first = -1, second = -1;
        for(int i = 0; i < inorder.size() - 1; ++i) {
            if(first == -1) {
                if(inorder[i].first > inorder[i+1].first) {
                    first = i;
                }    
            } else {
                if(inorder[i+1].first >= inorder[first].first) {
                    second = i;
                    swap(inorder[i].second->val, inorder[first].second->val);
                    break;
                }
            }
        }
        
        if(second == -1) {
            swap(inorder[inorder.size()-1].second->val, inorder[first].second->val);
        }
    }
};