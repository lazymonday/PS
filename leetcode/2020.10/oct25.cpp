#include <bits/stdc++.h>

using namespace std;

int dp[100000][2];

class Solution {
public:
    const int Alice = 0;
    const int Bob = 1;

    Solution() {
        memset(dp, -1, sizeof dp);
    }

    int solve(int n, int player) {
        if (n == 0) {
            return !player;  // winner
        }

        auto& ret = dp[n][player];
        if (ret != -1) {
            return ret;
        }

        ret = !player;
        for (int i = 1; i * i <= n; ++i) {
            if (solve(n - i * i, !player) == player) {
                ret = player;
                break;
            }
        }

        return ret;
    }

    bool winnerSquareGame(int n) {
        return (solve(n, Alice) == Alice);
    }
};

int main() {
    Solution sol;
    for(int i = 0; i < 100000; ++i) {
        auto ret = sol.winnerSquareGame(i);
        if(ret == 0) {
            cout << i << " : " << ret << "\n";
        }
    }
    // cout << sol.winnerSquareGame(50000);
    return 0;
}