class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        if (buckets <= 0) return 0;
        int times = (minutesToTest / minutesToDie) + 1;
        return ceil(log2(buckets) / log2(times));
    }
};