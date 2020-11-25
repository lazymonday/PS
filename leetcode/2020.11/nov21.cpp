class Solution {
public:
    int digit[10] = {0, };
    int freq[10] = {0, };
    int maxDepth = 0;
    bool walkAlongThreshold = true;

    int dfs(int n, int depth) {
        if (n == 0) return 0;
        maxDepth = max(depth, maxDepth);

        int ans = dfs(n / 10, depth + 1);
        int cur = n % 10;

        if (depth < maxDepth) {
            ans += pow(freq[9], depth);
        }

        if (walkAlongThreshold and cur > 1) {
            ans += pow(freq[9], depth - 1) * freq[cur - 1];
        }

        if (!digit[cur]) {
            walkAlongThreshold = false;
        }

        return ans;
    }

    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        for (auto x : digits) digit[x[0] - '0'] = 1;
        for (int i = 1; i < 10; ++i) freq[i] += (digit[i] + freq[i - 1]);
        auto ret = dfs(n, 1);
        if (walkAlongThreshold) ret++;
        return ret;
    }
};