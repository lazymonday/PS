/*
    Solved with priority queue (with index)
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < k; ++i) {
            pq.push({nums[i], i});
        }

        vector<int> ans;
        int n = nums.size();
        for (int i = k; i <= n; ++i) {
            ans.push_back(pq.top().first);

            while (!pq.empty() and pq.top().second <= i - k) pq.pop();

            if (i == n) break;
            pq.push({nums[i], i});
        }

        return ans;
    }
};