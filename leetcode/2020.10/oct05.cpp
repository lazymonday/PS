class Solution {
public:
    int bitwiseComplement(int N) {
        if(N == 0) return 1;
        bool foundMSB = false;
        int ans = 0;
        for(int i = 31; i >= 0; --i) {
            if(!foundMSB) {
                if((1 << i) & N) {
                    foundMSB = true;
                }    
            } else {
                if((1 << i) & ~N) {
                    ans |= (1<<i);
                }
            }
        }
                
        return ans;
    }
};