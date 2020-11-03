/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == 0) return "#";
        
        return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout << "data : " << data << "\n";
        stringstream ss(data);
        return deserialize_internal(ss);
    }
    
    TreeNode* deserialize_internal(stringstream& ss) {
        string s;
        ss >> s;
        if(s == "#") return nullptr;
        
        TreeNode *node = new TreeNode(stoi(s));
        node->left = deserialize_internal(ss);
        node->right = deserialize_internal(ss);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;