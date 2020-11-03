class Solution {
public:
    char findTheDifference(string s, string t) {
        int freq[26] = {0, };
        for(auto x : t) freq[x-'a']++;
        for(auto x : s) freq[x-'a']--;

        int ans = 0;
        for(int i = 0; i < 26; ++i) {
            if(freq[i]) {ans = i; break;}
        }
        
        return 'a' + ans;
    }
};