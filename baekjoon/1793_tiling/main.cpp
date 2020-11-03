#include <iostream>

using namespace std;

int dp[10000];

int tiling(int n) {

    if(n < 2) {
        return dp[n];
    }

    if (dp[n] != -1) {
        return dp[n];
    }

    int &ret = dp[n];
    ret = tiling(n - 1) + tiling(n - 2) * 2;
    return ret;
}

int main() {

    for (int i = 0; i < 10000; ++i) {
        dp[i] = -1;
    }

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 3;

    cout << tiling(12) << '\n';
    return 0;
}
