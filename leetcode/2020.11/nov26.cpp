#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int k;
    int findMin(int freq[26]) {
        int ret = 1e9;
        for (int i = 0; i < 26; ++i) {
            if (!freq[i]) continue;
            ret = min(freq[i], ret);
        }
        return ret;
    }

    int merge(string& s, int start, int end) {
        int ans = 0;
        for (int i = start; i <= end - k; ++i) {
            int freq[26] = {0, };
            for (int j = i; j <= end; ++j) {
                freq[s[j] - 'a']++;
                if (j - i + 1 < k) continue;
                int minVal = findMin(freq);
                if (k <= minVal) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }

    int partition(string& s, int start, int end) {
        if (end - start < k) {
            return 0;
        }

        int mid = start + (end - start) / 2;
        int left = partition(s, start, mid);
        int right = partition(s, mid + 1, end);
        int merged = merge(s, start, end);

        return max({left, right, merged});
    }

    int longestSubstring(string s, int k) {
        if (k == 1) return s.size();
        else if (k > s.size()) return 0;
        this->k = k;
        return partition(s, 0, s.size() - 1);
    }
};

int main() {
    Solution s;
    cout << s.longestSubstring("aaabbklfjalsdkfjadksljfkladsj", 3);
    return 0;
}