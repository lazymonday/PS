class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int total = 0;
        int last = 0;
        for(auto x : timeSeries) {
            if(last <= x) {
                total += duration;
            } else {
                total += (x + duration) - last;
            }
            last = x + duration;
        }
        
        return total;
    }
};