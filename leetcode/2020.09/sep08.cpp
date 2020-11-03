struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }

    int dfs(TreeNode* root, int sum) {
        if(!root) return 0;

        int cand = (sum << 1) + root->val;
        if(!root->left && !root->right) return cand;

        return dfs(root->left, cand) + dfs(root->right, cand);
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    return 0;
}