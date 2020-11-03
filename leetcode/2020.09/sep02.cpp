#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3;
const int INF = 1e9;
typedef long long ll;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> ordered;

        if (nums.size() < 2) return false;
        if (k == 0 && t == 0) return false;
        if (t < 0 || k <= 0) return false;

        for (int left = 0, right = 0; right < nums.size(); ++right)
        {
            if (ordered.insert(nums[right]).second) {
                if (right - left > k) {
                    if (right != left && nums[right] != nums[left]) {
                        ordered.erase(nums[left++]);
                    } else {
                        left++;
                    }
                }

                auto l = ordered.lower_bound(nums[right]);
                if (ordered.size() == 1) {
                    continue;
                }

                if (l == ordered.begin()) {
                    if (++l != ordered.end() && abs(*l - nums[right] * 1ll) <= t) {
                        return true;
                    }
                } else {
                    if (abs(*(--l) - nums[right] * 1ll) <= t) {
                        return true;
                    }
                    else {
                        ++l; ++l;
                        if (l != ordered.end() && abs(*l - nums[right] * 1ll) <= t) {
                            return true;
                        }
                    }
                }
            } else {
                if (right - left > k) {
                    if (right != left && nums[right] != nums[left]) {
                        ordered.erase(nums[left++]);
                    } else {
                        left++;
                    }
                } else {
                    return true;
                }
            }
        }

        return false;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Solution s;

    //vector<int> a = {7, 1, 3};   // 2, 3
    // vector<int> a = {1, 5, 9, 1, 5, 9};  // 2, 3
    //vector<int> a = {1, 2, 3, 1};   // 3, 0
    // vector<int> a = {2, 1}; // 1, 1
    //vector<int> a = { -3, 3};   // 2, 4
    // vector<int> a = {1, 2}; // 0, 1
    // vector<int> a = {2, 1};  // 1, 1, true
    vector<int> a = {1, 0, 1, 1};   // 1, 2, true
    cout << (s.containsNearbyAlmostDuplicate(a, 1, 2) ? "true " : "false");

    return 0;
}
