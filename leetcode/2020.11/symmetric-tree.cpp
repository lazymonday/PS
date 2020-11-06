// Problem : https://leetcode.com/problems/symmetric-tree

class Solution {
public:
    // Iterative version
    bool isSymmetric(TreeNode* root) {
        if (root == 0) return true;

        stack<TreeNode*> left, right;
        left.push(root->left);
        right.push(root->right);

        while (!left.empty() and !right.empty()) {
            auto l = left.top();
            auto r = right.top();

            left.pop(), right.pop();

            if (l == 0 and r == 0) continue;
            if (!l || !r || l->val != r->val) {
                return false;
            }

            left.push(l->left);
            left.push(l->right);
            right.push(r->right);
            right.push(r->left);
        }

        return left.size() == right.size();
    }

    // Recursive version
    bool isSymmetric2(TreeNode* root) {
        if (!root) return false;
        return isMirror(root->left, root->right);
    }

    bool isMirror(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        if (!left || !right) return false;
        return (left->val == right->val) &&
               isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }
};

