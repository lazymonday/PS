#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& a) {
        const int INF = 1e9;
        int n = a.size();
        int minv = a[0];
        int maxv = a[0];
        for (int i = 1; i < n; ++i) {
            if (minv > a[i]) {
                maxv = minv = a[i];
                continue;
            }

            maxv = max(a[i], maxv);
            if(maxv == minv) continue;
            for (int j = i + 1; j < n; ++j) {
                if (minv < a[j] and a[j] < maxv) return true;
            }
        }

        return false;
    }
};


int main() {
    return 0;
}