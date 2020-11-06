class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1, hi = 1e6 + 1;
        while (lo < hi) {
            int x = lo + (hi - lo) / 2;

            auto isOK = [&]() {
                int sum = 0;
                for (int i = 0; i < nums.size(); ++i) {
                    int division = (nums[i] + x - 1) / x;
                    sum += division;
                }

                return threshold >= sum;
            };

            if (isOK()) {
                hi = x;
            } else {
                lo = x + 1;
            }
        }

        return lo;
    }
};