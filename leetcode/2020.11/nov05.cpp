class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd = 0;
        for(auto x : position) {
            if(x & 1) odd++;
        }
        
        return min(odd, (int)position.size() - odd);
    }
};