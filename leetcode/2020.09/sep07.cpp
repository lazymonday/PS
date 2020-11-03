#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3;
const int INF = 1e9;
typedef long long ll;

class Solution {
public:
    bool wordPattern(string pattern, string str) {

        for (int i = 0; i < pattern.size(); ++i) pattern[i] -= 'a';

        string tbl[30];
        set<string> used;
        size_t pos = 0, prev = 0;
        int idx = 0;
        while ((pos = str.find(' ', pos)) != string::npos) {
            string word = str.substr(prev, pos - prev);
            int currId = pattern[idx];
            if (tbl[currId].empty()) {
                if (used.find(word) != used.end()) return false;
                used.insert(word);
                tbl[currId] = word;
            } else {
                if (tbl[currId] != word) {
                    return false;
                }
            }
            prev = ++pos;
            idx++;
        }

        string word = str.substr(prev);
        int currId = pattern[idx];
        if (tbl[currId].empty()) {
            if (used.find(word) != used.end()) return false;
            used.insert(word);
            tbl[currId] = word;
        } else {
            if (tbl[currId] != word) {
                return false;
            }
        }

        if (idx != pattern.size() - 1) return false;

        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Solution s;
    string str = "aa aa aa aa";
    string pattern = "aaa";
    // string str = "dog cat cat fish";
    // string pattern = "abba";

    cout << s.wordPattern(pattern, str);

    return 0;
}
