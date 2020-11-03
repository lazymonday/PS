#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;

        int minv = prices[0];
        int ans = 0;
        for (int i = 0; i < prices.size(); ++i) {
            ans = max(ans, prices[i] - minv);

            if (prices[i] < minv) {
                minv = prices[i];
            }
        }

        return ans;
    }
};

int main() {

    map<int, int> freq;
    freq[10]++;
    // freq[12]++;
    // freq[13]++;

    auto itr = freq.lower_bound(11);
    cout << itr->first;

    return 0;
}