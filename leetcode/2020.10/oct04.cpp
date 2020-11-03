class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& lhs, const vector<int>& rhs) {
            if(lhs[1] == rhs[1]) return lhs[0] > rhs[0];
            return lhs[1] < rhs[1];
        });
        
        int ans = 0;
        for(int i = 0; i < intervals.size(); ++i) {
            int l = intervals[i][0], r = intervals[i][1];
            bool isOverlapped = false;
            for(int j = i + 1; j < intervals.size(); ++j) {
                if(intervals[j][0] <= l and r <= intervals[j][1]) {
                    isOverlapped = true;
                    break;
                }
            }
            
            if(!isOverlapped) ans++;
        }
        
        return ans;
    }
};