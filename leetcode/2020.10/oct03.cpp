class Solution {
public:
    int findPairs(vector<int>& a, int k) {
        
        unordered_map<int, int> freq;
        for(auto x : a) {
            freq[x]++;
        }
        
        int ans = 0;
        for(auto [key, v] : freq) {
            if((k > 0 and freq.count(key+k) > 0) || (k == 0 and freq[key] >= 2)) 
                ans++;
        }
        
        return ans;
    }
};