class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& a, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);

        typedef long long ll;

        int n = a.size(), r = 0;
        ll prod = 1, ans = 0;

        for (int i = 0; i < n; ++i) {
            if (a[i] >= k) {
                prod = 1;
                continue;
            }

            r = max(r, i);
            while (r < n && prod * a[r] < k) prod *= a[r++];
            ans += r - i;
            prod /= a[i];
        }

        return ans;
        
    }
};