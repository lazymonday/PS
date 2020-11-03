#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3;
const int INF = 1e9;
typedef long long ll;

class Solution {
public:
    vector<int> partitionLabels(string s) {

        int firstPos[26] = {0, };
        int freq[26] = {0, };
        int group[505] = {0, };

        vector<int> ret;
        for (int i = 0; i < s.size(); ++i) {
            int letter = s[i] - 'a';
            freq[letter]++;

            if (freq[letter] == 1) {
                ret.push_back(1);
                firstPos[letter] = i;
                group[i] = ret.size() - 1;
            } else {
                ret.push_back(1);
                int mergeTo = group[firstPos[letter]];
                for (int k = firstPos[letter] + 1; k <= i; ++k) {
                    group[k] = mergeTo;
                }

                int sum = 0;
                while (ret.size() > mergeTo + 1) {
                    sum += ret.back();
                    ret.pop_back();
                }

                ret[mergeTo] += sum;
            }
        }

        return ret;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str = "abaccbdeffed";
    // string str = "abb";

    Solution s;
    auto ret = s.partitionLabels(str);
    for (auto x : ret) {
        cout << x << ", ";
    }

    return 0;
}