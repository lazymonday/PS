class Solution {
public:
    
    int getSeq(int startDigit, int len) {
        int ret = startDigit;
        for(int i = 1; i < len; ++i) {
            if(startDigit + i > 9) return -1;
            ret *= 10;
            ret += startDigit + i;
        }
        return ret;
    }
    
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        
        for(int len = 2; len <= 9; ++len) {
            for(int i = 1; i <= 9; ++i) {
                auto val = getSeq(i, len);
                if(val < low || val > high) continue;
                ans.push_back(val);
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};