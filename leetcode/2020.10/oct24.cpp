class Solution {
public:

    int bagOfTokensScore(vector<int>& a, int P) {
        int n = a.size();
        if (n == 0) return 0;
        sort(a.begin(), a.end());

        int ans = 0;
        int score = 0;
        int power = P;
        int l = 0, r = n - 1;
        int seen[n];
        memset(seen, 0, sizeof seen);

        for (int i = 0; i < n; ++i) {
            if (r < i) break;

            if (a[i] <= power) {
                ans = max(++score, ans);
                power -= a[i];
            }
            else if (score > 0) {
                // get more power from right
                power += a[r--];
                ans = max(score--, ans);
                --i;
            } else {
                break;
            }
        }

        return ans;
    }
};