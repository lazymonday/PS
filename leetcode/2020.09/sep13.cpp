class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& ni) {
        vector<vector<int>> ret;

        int curr = 0;
        for (int i = 0 ; i < intervals.size(); ++i) {
            if (intervals[i][1] < ni[0]) {
                ret.push_back(intervals[i]);
                ++curr;
            } else if (ni[1] < intervals[i][0]) {
                ret.push_back(intervals[i]);
            } else {
                ni[0] = min(ni[0], intervals[i][0]);
                ni[1] = max(ni[1], intervals[i][1]);
            }
        }

        ret.insert(ret.begin() + curr, ni);
        return ret;
    }
};