#include <bits/stdc++.h>

using namespace std;

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
    
    void dfs(TreeNode* node, vector<int>& out) {
        if(node == 0) return;
        
        dfs(node->left, out);
        out.push_back(node->val);
        dfs(node->right, out);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> t1, t2;
        dfs(root1, t1);
        dfs(root2, t2);
        
        vector<int> ans(t1.size() + t2.size());
        int i = 0, j = 0, curr = 0;
        while(i < t1.size() && j < t2.size()) {
            if(t1[i] <= t2[j]) {
                ans[curr++] = t1[i++];
            } else {
                ans[curr++] = t2[j++];
            }
        }
        
        for(int k = i; k < t1.size(); ++k) {
            ans[curr++] = t1[k];
        }
        
        for(int k = j; k < t2.size(); ++k) {
            ans[curr++] = t2[k];
        }
        
        return ans;
    }
};