/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloned[101];
    int visited[101];

    Solution() {
        memset(visited, 0, sizeof visited);
        memset(cloned, 0, sizeof cloned);
    }

    Node* cloneGraph(Node* node) {
        if (node == 0 or visited[node->val]) return 0;
        visited[node->val] = 1;

        auto ret = cloned[node->val] = new Node(node->val);
        for (auto x : node->neighbors) {
            Node* neighbor = visited[x->val] ? cloned[x->val] : cloneGraph(x);
            ret->neighbors.push_back(neighbor);
        }

        return ret;
    }
};