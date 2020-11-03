class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& pt) {
        if(pt.size() == 0) return 0;
        sort(pt.begin(), pt.end());

        int right = pt[0][1];
        int ans = 1;
        for(int i = 1; i < pt.size(); ++i) {
            if(right < pt[i][0]) {
                ans++;
                right = pt[i][1];
            } else {
                right = min(pt[i][1], right);
            }
        }
        
        return ans;
    }
};