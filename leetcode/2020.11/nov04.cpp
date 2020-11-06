#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e4+20;
int removed[MAX];
int seen[MAX];

class Solution {
public:
    vector<int> adj[MAX];
    
    void removeLeaf(int u, int root) {
        if(u != root and adj[u].size() == 1) {
            removed[u] = 1;
            return;
        }
        
        seen[u] = true;
        for(auto v : adj[u]) {
            if(seen[v] || removed[v]) continue;
            removeLeaf(v, root);
        }
    }
    
    int dfs(int pos) {
        seen[pos] = true;
        int ret = 0;
        for(auto v : adj[pos]) {
            if(seen[v]) continue;
            ret = max(ret, dfs(v));
        }
        
        return ret + 1;
    }
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return vector<int>({0});
        else if(n == 2) return vector<int>({0, 1});
        
        for(auto x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        memset(seen, 0, sizeof seen);
        memset(removed, 0, sizeof removed);
        for(int i = 0; i < n; ++i) {
            if(removed[i]) continue;
            removeLeaf(i, i);
        }

        vector<int> ans;
        int most = 1e9;
        for(int i = 0; i < n; ++i) {
            if(!removed[i]) {
                memset(seen, 0, sizeof seen);
                // cout << "candidate : " << i << ", depth : ";
                auto ret = dfs(i);
                // cout << ret << "\n";
                if(most > ret) {
                    most = ret;
                    ans.clear();
                    ans.push_back(i);
                } else if(most == ret) {
                    ans.push_back(i);
                }
                
                if(ans.size() == 2) break;
            }
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges;
    edges.push_back({3,0});
    edges.push_back({3,1});
    edges.push_back({3,2});
    edges.push_back({3,4});
    edges.push_back({5,4});
    auto ret = sol.findMinHeightTrees(6, edges);
    for(auto x : ret) {
        cout << x << ", ";
    }
    return 0;
}