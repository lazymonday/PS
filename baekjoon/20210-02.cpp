#include <bits/stdc++.h>

using namespace std;


// WA

bool natrualComparator(const string& lhs, const string& rhs) {
    int llen = lhs.size(), rlen = rhs.size();
    int l = 0, r = 0;
    while (l < lhs.size() and r < rhs.size()) {
        if (!isdigit(lhs[l]) or !isdigit(rhs[r])) {
            if (lhs[l] == rhs[r]) {
                l++, r++;
                continue;
            }

            if (isalpha(lhs[l]) and isalpha(rhs[r])) {
                int ul = toupper(lhs[l]);
                int ur = toupper(rhs[r]);

                if (ul == ur) {
                    return lhs[l] < rhs[r];
                }

                return ul < ur;
            }

            return lhs[l] < rhs[l];
        }

        int lzl = 0;
        int lend = l;
        bool noMoreZero = false;
        while (lend < llen and isdigit(lhs[lend])) {
            if (lhs[lend] != '0') noMoreZero = true;
            if (!noMoreZero and lhs[lend] == '0') lzl++;
            ++lend;
        }
        lend--;

        int lzr = 0;
        int rend = r;
        noMoreZero = false;
        while (rend < rlen and isdigit(rhs[rend])) {
            if (rhs[rend] != '0') noMoreZero = true;
            if (!noMoreZero and rhs[rend] == '0') lzr++;
            ++rend;
        }
        rend--;

        int len1 = lend - l + 1;
        int len2 = rend - r + 1;

        if (len1 == len2) { // same len
            for (int i = 0; i < len1; ++i) {
                if (lhs[l + i] != rhs[r + i]) {
                    return lhs[l + i] < rhs[r + i];
                }
            }
        } else {    // diff len
            if (len1 - lzl == len2 - lzr) {
                int upper = len1 - lzl;
                for (int i = 0; i < upper; ++i) {
                    if (lhs[lend - i] != rhs[rend - i]) {
                        return lhs[lend - i] < rhs[rend - i];
                    }
                }

                return lzl < lzr;
            } else {
                return (len1 - lzl) < (len2 - lzr);
            }
        }

        l = lend + 1, r = rend + 1;
    }

    if (r < rlen) return true;
    return false;
}

int n;
int MAX = 1e4 + 10;
vector<string> str;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    str.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> str[i];
    }

    sort(str.begin(), str.begin() + n, natrualComparator);

    for (int i = 0; i < n; ++i) {
        cout << str[i] << "\n";
    }

    return 0;
}