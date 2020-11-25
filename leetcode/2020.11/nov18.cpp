class Solution {
public:
    const int INF = 1e9;
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        intervals.push_back(vector<int>({INF, INF}));
        vector<vector<int>> ans;
        int l = intervals[0][0], r = intervals[0][1];
        for (auto x : intervals) {
            if (l <= x[0] and x[0] <= r) {
                r = max(r, x[1]);
            } else {
                ans.push_back(vector<int>({l, r}));
                l = x[0], r = x[1];
            }
        }

        return ans;
    }
};