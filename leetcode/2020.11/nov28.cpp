#include <bits/stdc++.h>

using namespace std;

/*
    Solution with segment tree
*/

class Solution {
public:
    vector<int> tree;

    void init(int node, int left, int right, vector<int>& nums) {
        if (left == right) {
            tree[node] = nums[left - 1];
            return;
        }

        int mid = left + (right - left) / 2;
        init(node * 2, left, mid, nums);
        init(node * 2 + 1, mid + 1, right, nums);
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    int query(int node, int left, int right, int l, int r) {
        if (r < left or right < l) {
            return -1e9;
        }

        if (l <= left and right <= r) {
            return tree[node];
        }

        int mid = left + (right - left) / 2;
        return max(query(node * 2, left, mid, l, r), query(node * 2 + 1, mid + 1, right, l, r));
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int treeSZ = pow(2, ceil(log2(n)) + 1);
        tree.resize(treeSZ, 0);
        init(1, 1, n, nums);
        vector<int> ans;
        for (int i = 1; i <= n - k + 1; ++i) {
            int ret = query(1, 1, n, i, i + k - 1);
            cout << ret << ", ";
            ans.push_back(ret);
        }

        return ans;
    }
};

int main() {

    Solution s;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    s.maxSlidingWindow(nums, 3);
    return 0;
}