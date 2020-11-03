class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size() != B.size()) return false;

        int same = 0, diff = 0;
        int pos[2];
        int cur = 0;
        int freq[26] = {0, };
        bool existSame = false;
        for(int i = 0; i < A.size(); ++i) {
            if(A[i] != B[i]) {
                diff++;
                if(diff <= 2) pos[cur++] = i;
            } else {
                same++;
                if(++freq[A[i]-'a'] >= 2) existSame = true;
            }
        }
        
        if(diff == 2) {
            return A[pos[0]] == B[pos[1]] and A[pos[1]] == B[pos[0]];
        } else if(same >= 2 and diff == 0) {
            return existSame;
        }
        
        return false;
    }
};