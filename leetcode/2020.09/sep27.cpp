class Solution {
public:
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        unordered_map<string, int> tbl;
        double adj[22][22];
        
        for(int i = 0; i < 22; ++i) for(int j = 0; j < 22; ++j) {
            if(i == j) {
                adj[i][j] = 1.0;
                continue;
            }
            adj[i][j] = 0.0;
        }
        
        int index = 0;
        
        for(int i = 0; i < equations.size(); ++i) {
            const string& var1 = equations[i][0];
            const string& var2 = equations[i][1];
            
            if(tbl.find(var1) == tbl.end()) {
                tbl[var1] = index++;
            }
            int first = tbl[var1];
            
            if(tbl.find(var2) == tbl.end()) {
                tbl[var2] = index++;
            }
            int second = tbl[var2];
            
            adj[first][second] = values[i];
            adj[second][first] = 1.0 / values[i];
        }
        
        int n = index;
      
        // floyd-warshall
        for(int k = 0; k < n; ++k) {
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    if(i == j) continue;
                    if(adj[i][k] > 0.0 && adj[k][j] > 0.0) 
                        adj[i][j] = adj[i][k] * adj[k][j];
                }
            }
        }
        
        vector<double> ret;
        for(int i = 0; i < queries.size(); ++i) {
            const string& var1 = queries[i][0];
            const string& var2 = queries[i][1];
            
            if(tbl.find(var1) == tbl.end() || tbl.find(var2) == tbl.end()) {
                ret.push_back(-1.0);
                continue;
            }
            
            int start = tbl[var1];
            int end = tbl[var2];
            
            if(adj[start][end] > 0) {
                ret.push_back(adj[start][end]);
            } else if(adj[end][start] > 0) {
                ret.push_back(1.0 / adj[end][start]);
            } else {
                ret.push_back(-1.0);
            }
        }
       
        return ret;
    }
};