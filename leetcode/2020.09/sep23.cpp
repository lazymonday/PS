class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size();
        int psum = 0, maxVal = 0;
        int pos = 0;
        for(int i = len-1; i >= 0; --i) {
            psum += gas[i] - cost[i];
            if(maxVal <= psum) {
                maxVal = psum;
                pos = i;
            }
        }
        
        if(psum < 0) return -1;
        return pos;
    }
};