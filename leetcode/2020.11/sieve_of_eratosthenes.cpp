#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        int notPrime[n + 1];
        notPrime[0] = 1;
        notPrime[1] = 1;
        notPrime[2] = 0;
        memset(notPrime, 0, sizeof notPrime);
        for (int i = 2; i * i <= n; ++i) {
            if (notPrime[i] != 0) continue;
            for (int j = 2; j*i <= n; j++) {
                notPrime[j*i] = 1;
            }
        }

        int ans = 0;
        for (int i = 2; i <= n; ++i) {
            if (!notPrime[i]) {
                cout << i << " ";
                ans++;
            }
        }

        cout << "\n";
        return ans;
    }
};


int main() {
    Solution s;
    s.countPrimes(20);
    return 0;
}