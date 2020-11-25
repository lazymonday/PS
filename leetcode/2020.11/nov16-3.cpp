class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n = A.size();
        if (n <= 2) return 0;

        int ans = 0, l = 0, start = 0;
        while (l < n) {
            l = start;
            if (l + 1 < n and A[l] < A[l + 1]) {
                while (l + 1 < n and A[l] < A[l + 1]) l++;

                if (l + 1 < n and A[l] > A[l + 1]) {
                    while (l + 1 < n and A[l] > A[l + 1]) l++;
                    ans = max(ans, l - start + 1);
                }
            }

            start = max(start + 1, l);
        }

        return ans;
    }
};