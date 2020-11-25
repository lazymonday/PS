/*
    DP로 안풀고 그냥 무식하게 푼 듯
    케이스가 제대로 정리가 안되서 많이 헤맸다.

    예외 케이스로 걸릴만 한 것들

    ["7"]
    8

    ["5","6"]
    19

    ["1","2","4","6","7","9"]
    333


    ["1","2","3","4","6","7","9"]
    333
    303

    ["1","4","9"]
    1000000000

    ["1","3","5","7"]
    100
*/

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

        // 경계에 걸릴 때만 잘 처리해주면 되는데 꽤 까다로웠다
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