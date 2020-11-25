#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& A) {
        if (A.size() <= 2) return 0;

        int ans = 0, pos = 0, neg = 0;
        for (int i = 1; i < A.size(); ++i) {
            int dt = A[i] - A[i - 1];
            if (dt > 0) {
                if (neg > 0) pos = 0;
                pos++;
                neg = 0;
            } else if (dt < 0) {
                if (pos > 0) {
                    neg++;
                    ans = max(ans, pos + neg + 1);
                }
            } else {
                pos = neg = 0;
            }

        }

        return ans;
    }
};

int main() {
    return 0;
}