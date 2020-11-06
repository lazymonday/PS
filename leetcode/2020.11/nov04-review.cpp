#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    const int MAX = 2e4 + 20;
        
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return vector<int>({0});
        else if(n == 2) return vector<int>({0, 1});
        
        vector<int> adj[MAX];
        for(auto x : edges) {
            int u = x[0], v = x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }


        vector<bool> seen(n, false);        
        queue<int> q;
        for(int i = 0; i < n; ++i) {
            if(adj[i].size() == 1) {
                q.push(i);
            }
        }

        int remain = n;
        while(remain > 2) {
            int sz = q.size();
            remain -= sz;

            for(int i = 0; i < sz; ++i) {
                auto curr = q.front();
                q.pop();

                for(auto v : adj[curr]) {
                    if(adj[v].size() == 1) continue;
                    auto itr = find(adj[v].begin(), adj[v].end(), curr);
                    *itr = adj[v].back();
                    adj[v].pop_back();
                    
                    if(adj[v].size() == 1) q.push(v);
                }    
            }
        }

        vector<int> ans;
        while(!q.empty()) {
            ans.emplace_back(q.front());
            q.pop();
        }
        
        return ans;
    }
};


int main() {
    return 0;
}