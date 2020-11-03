#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    vector<vector<int>> ans;

    vector<vector<int>> combinationSum3(int k, int n) {

        int digit[10] = {0, };
        vector<int> selected;
        solve(digit, k, n, 0, selected);
        return ans;
    }

    void solve(int* digits, int k, int n, int start, vector<int>& selected) {

        if (k == 0) {
            if (n == 0) ans.push_back(selected);;
            return;
        }

        digits[start] = 1;
        for (int i = start + 1; i <= 9; ++i) {
            if (!digits[i]) {
                selected.push_back(i);
                solve(digits, k - 1, n - i, i, selected);
                selected.pop_back();
            }
        }

        digits[start] = 0;
    }
};

int main() {
    return 0;
}