#include <bits/stdc++.h>

using namespace std;

struct Node {
    Node* zero = 0;     // 0
    Node* one = 0;    // 1
};

class Solution {
public:

    void insert(int num, Node* root) {

        Node* curr = root;
        for (int i = 31; i >= 0; --i) {
            if ((num >> i) & 1) {
                if (!curr->one) {
                    curr->one = new Node();
                }
                curr = curr->one;
            } else {
                if (!curr->zero) {
                    curr->zero = new Node();
                }
                curr = curr->zero;
            }
        }
    }

    int maxXor(int num, Node* root) {
        int candNum = 0;
        Node* curr = root;
        for (int i = 31; i >= 0; --i) {
            bool isOne = ((num >> i) & 1) == 1;
            candNum <<= 1;
            if (isOne) {
                if (curr->zero) {
                    curr = curr->zero;
                } else {
                    curr = curr->one;
                    candNum |= 1;
                }
            } else {    // zero
                if (curr->one) {
                    curr = curr->one;
                    candNum |= 1;
                } else {
                    curr = curr->zero;
                }
            }
        }

        return num ^ candNum;
    }

    int findMaximumXOR(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        int ans = 0;
        Node* root = new Node();
        for (auto x : nums) {
            insert(x, root);
            ans = max(ans, maxXor(x, root));
        }

        return ans;
    }
};

int main() {
    return 0;
}