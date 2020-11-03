class Solution {
public:
    string removeDuplicateLetters(string s) {
        int last[26];
        int first = -1;
        memset(last, -1, sizeof last);
        for(int i = s.size()-1; i>=0; --i) {
            int curr = s[i];
            if(last[curr - 'a'] == -1) {
                last[curr - 'a'] = i;
                first = i;
            } else {
                if(s[first] > curr) {
                    s[last[curr - 'a']] = ' ';
                    last[curr - 'a'] = i;
                    first = i;
                } else {
                    s[i] = ' ';
                }
            }
        }
        
        char ret[27];
        int cur = 0;
        for(auto x : s) {
            if(x != ' ') {
                ret[cur++] = x;
            }
        }
        ret[cur] = '\0';
        return string(ret);
    }
};