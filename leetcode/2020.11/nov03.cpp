class Solution {
public:
    int maxPower(string s) {
        int n = s.size();
        if(n <= 1) return 1;
        
        int cand = 1;
        int ans = 1;
        for(int i = 1; i < s.size(); ++i) {
            if(s[i] == s[i-1]) {
                ans = max(ans, ++cand);
            } else {
                cand = 1;
            }
        }
        
        return ans;
    }
};