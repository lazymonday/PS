class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        int indegree[numCourses];
        memset(indegree, 0, sizeof indegree);   // init with zeros
        
        // build course graph and count 
        for(auto edge : prerequisites) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int> q;
        // put it all that indegree equals to zero
        for(int i = 0; i < numCourses; ++i) {
            if(indegree[i] == 0) q.push(i);
        }
        
        int visited = 0;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            visited++;
            
            for(auto v : adj[cur]) {
                // remove current course and recalculate it.
                if(--indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        return (visited == numCourses);
    }
};