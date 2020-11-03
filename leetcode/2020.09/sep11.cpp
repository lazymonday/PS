class Solution {
public:
    int maxProduct(vector<int>& a) {

        int cur_max = a[0];
        int cur_min = a[1];
        int prev_max = a[0];
        int prev_min = a[0];
        int ans = a[0];

        for(int i = 1; i < a.size(); ++i) {
            cur_max = max(a[i], max(prev_max*a[i], prev_min*a[i]));
            cur_min = min(a[i], min(prev_max*a[i], prev_min*a[i]));

            ans = max(ans, cur_max);

            prev_max = cur_max;
            prev_min = cur_min;
        }

        return ans;
    }
};