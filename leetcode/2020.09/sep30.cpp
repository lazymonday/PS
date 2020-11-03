class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int cnt = 0;
        int minval = INT_MAX, maxval = 0;
        int cand = 1;
        unordered_map<int, int> freq;
        for(auto x : nums) {
            if(x < 0) continue;
            cnt++;
            freq[x] = 1;
            if(x == cand) {
                while(freq.find(++cand) != freq.end());
            }
        }
        
        return cand;
    }
};