class Solution {
public:
    string removeDuplicateLetters(string s) {
        int last[26] = {0,};
        for(int i = 0; i < s.size(); ++i) {
            last[s[i]-'a'] = i;
        }

        stack<int> st;
        int seen[26] = {0, };
        for(int i = 0; i < s.size(); ++i) {
            int c = s[i] - 'a';
            if(seen[c]) continue;

            while(!st.empty() and st.top() > c and i < last[st.top()]) {
                seen[st.top()] = false;
                st.pop();
            }

            st.push(c);
            seen[c] = true;
        }

        string ret;
        while(!st.empty()) {
            ret += st.top() + 'a';
            st.pop();
        }
        
        reverse(ret.begin(), ret.end());
        return ret;
    }
};