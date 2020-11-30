class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<int> targets;
        int n = arr.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; ++i) {
            if (arr[i] == 0) {
                targets.push_back(i);
                continue;
            }

            if (i + arr[i] < n) adj[i].push_back(i + arr[i]);
            if (i - arr[i] >= 0) adj[i].push_back(i - arr[i]);
        }

        int dist[n];
        memset(dist, 0x63, sizeof dist);
        priority_queue<pair<int, int>> pq;
        pq.push({0, start});
        dist[start] = 0;

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int cost = -top.first;
            int here = top.second;
            if (dist[here] < cost) continue;
            for (auto next : adj[here]) {
                if (dist[next] > dist[here] + 1) {
                    dist[next] = dist[here] + 1;
                    pq.push({ -dist[next], next});
                }
            }
        }

        for (auto x : targets) {
            if (dist[x] != 0x63636363) return true;
        }

        return false;
    }
};