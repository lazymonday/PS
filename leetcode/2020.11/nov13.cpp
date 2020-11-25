/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root, Node* parent) {
        if (!root) return 0;

        if (root->left and root->right) {
            root->left->next = root->right;
        }

        if (!root->next and parent and parent->next and parent->next->left) {
            root->next = parent->next->left;
        }

        connect(root->left, root);
        connect(root->right, root);
        return root;
    }

    Node* connect(Node* root) {
        return connect(root, 0);
    }
};