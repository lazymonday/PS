class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        if (s.size() < 10) return ans;

        int sz = s.size();
        unordered_map<int, int> freq;

        int val = 0;
        int mask = (1 << 20) - 1;
        for (int i = 0; i < sz; ++i) {
            int k = 0;
            switch (s[i]) {
                case 'A': k = 0; break;
                case 'C': k = 1; break;
                case 'G': k = 2; break;
                case 'T': k = 3; break;
            }
            val <<= 2;
            val |= k;
            if(i < 9) continue;
            
            val &= mask;
            if(++freq[val] == 2) {
                string ret;
                for(int j = 0; j < 10; ++j) {
                    char ch = 'A';
                    switch((val >> (9-j)*2) & 3) {
                        case 0: ch = 'A'; break;
                        case 1: ch = 'C'; break;
                        case 2: ch = 'G'; break; 
                        case 3: ch = 'T'; break;
                    }
                    ret += ch;
                }
                ans.push_back(ret);
            }
        }
        return ans;
    }
};