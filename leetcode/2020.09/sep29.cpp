

class Solution {
public:
    vector<int> dp;
    
    struct Node {
        Node* nodes[26];
        bool isWord = false;

        Node() {
            memset(nodes, 0, sizeof nodes);
        }
    };
    
    Node root;
    
    void insert(const string& s, Node& node) {
        Node* cur = &node;
        for(int i = 0; i < s.size(); ++i) {
            int index = s[i] - 'a';
            if(!cur->nodes[index]) {
                cur->nodes[index] = new Node();
            }
            cur = cur->nodes[index];
        }
        cur->isWord = true;
    }

    bool solve(const string&s, int pos, Node& node) {
        if(pos == s.size()) {
            return true;
        }
        
        Node* cur = &node;
        int depth = 0;
        for(int i = pos; i < s.size(); ++i) {
            int index = s[i] - 'a';
            if(!cur->nodes[index]) {
                return false;
            }

            depth++;
            cur = cur->nodes[index];
            if(cur->isWord) {
                if(dp[pos] < depth) {
                    if(solve(s, i+1, node)) return true;
                    else dp[pos] = depth;
                } else {
                    return false;
                }
            }
        }

        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.empty()) return false;
        for(auto x : wordDict) {
            insert(x, root);
        }
        
        dp.resize(s.size(), 0);
        return solve(s, 0, root);
    }
};