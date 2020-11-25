class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n = A.size();
        if (n <= 2) return 0;

        vector<int> inc, dec;
        inc.resize(n, 1);
        dec.resize(n, 1);

        for (int i = 0; i < n - 1; ++i) {
            if (A[i] < A[i + 1]) inc[i + 1] = inc[i] + 1;
        }

        for (int i = n - 2; i >= 0; --i) {
            if (A[i] > A[i + 1]) dec[i] = dec[i + 1] + 1;
        }

        int ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (inc[i] > 1 and dec[i] > 1) {
                ans = max(ans, inc[i] + dec[i] - 1);
            }
        }

        return ans;
    }
};