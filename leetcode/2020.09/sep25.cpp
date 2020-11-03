class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> a(nums.size());
        for(int i = 0; i < nums.size(); ++i) {
            a[i] = to_string(nums[i]);
        }
        
        sort(a.begin(), a.end(), [](const string& lhs, const string& rhs) {
            return lhs + rhs < rhs + lhs;
        });
     
        string ret;
        for(auto itr = a.rbegin(); itr != a.rend(); ++itr) {
            if(itr == a.rbegin() && (*itr)[0] == '0') return "0";
            ret += *itr;
        }

        
        return ret;
    }
};