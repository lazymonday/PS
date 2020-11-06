class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<int> curLevelNodes;
            for (int i = 0; i < sz; ++i) {
                auto cur = q.front();
                q.pop();
                if (!cur) continue;
                q.push(cur->left);
                q.push(cur->right);
                curLevelNodes.push_back(cur->val);
            }
            if (curLevelNodes.size())
                ans.push_back(curLevelNodes);
        }
        return ans;
    }
};