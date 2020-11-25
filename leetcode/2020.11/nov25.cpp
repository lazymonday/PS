#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int K) {
        int remainder = 1;
        int ans = 1;
        
        int n = 0;
        int tmp; 
        while(remainder % K) {
            n = remainder * 10 + 1;
            remainder = n % K;
            cout << remainder << "\n";
            ans++;
            cin >> tmp;
        }
        
        return ans;
    }
};

int main() {
    Solution s;

    s.smallestRepunitDivByK(1000);

    return 0;
}