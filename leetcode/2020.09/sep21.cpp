class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        int road[1020] = {0, };
        for(auto trip : trips) {
            road[trip[1]] += trip[0];
            road[trip[2]] -= trip[0];
        }
        
        int psum = road[0];
        for(int i = 1; i <= 1000; ++i) {
            psum += road[i];
            if(psum > capacity) return false;
        }
        
        return true;
    }
};