#include <bits/stdc++.h>

using namespace std;

int n;
int MAX = 1e4 + 10;
vector<vector<string>> str;

int leadingZeroCnt(const string& s) {
    int cnt = 0;
    for (auto x : s) {
        if (x == '0') cnt++;
        else break;
    }
    return cnt;
}

bool comp(const vector<string> lhs, const vector<string>& rhs) {

    int llen = lhs.size(), rlen = rhs.size();
    int l = 0, r = 0;
    while (l < llen and r < rlen) {


        if (lhs[l] == rhs[r]) {
            ++l, ++r;
            continue;
        }


        if (isdigit(lhs[l][0]) and isdigit(rhs[r][0])) {
            int llzc = leadingZeroCnt(lhs[l]);
            int rlzc = leadingZeroCnt(rhs[r]);

            auto len1 = lhs[l].size() - llzc;
            auto len2 = rhs[r].size() - rlzc;
            if (len1 == len2) {
                int ret = lhs[l].compare(llzc, len1, rhs[r], rlzc, len2);
                if (ret == 0) return llzc < rlzc;
                return ret < 0;
            } else {
                if (len1 < len2) return true;
                else return false;
            }
        } else if (isalpha(lhs[l][0]) and isalpha(rhs[r][0])) {
            int len1 = lhs[l].size();
            int len2 = rhs[r].size();

            for (int i = 0; i < min(len1, len2); ++i) {
                char ll = toupper(lhs[l][i]);
                char rr = toupper(rhs[r][i]);
                if (ll == rr) {
                    if (lhs[l][i] == rhs[r][i]) continue;
                    else {
                        return lhs[l][i] < rhs[r][i];
                    }
                }

                return ll < rr;
            }
        }

        return lhs[l] < rhs[r];
    }

    if (r < rlen) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    str.resize(n);
    for (int k = 0; k < n; ++k) {
        string p;
        cin >> p;

        int start = 0;
        bool digitCur = isdigit(p[0]);
        for (int i = 1; i < p.size(); ++i) {
            if (digitCur) {
                if (!isdigit(p[i])) {
                    str[k].push_back(p.substr(start, i - start));
                    start = i;
                }
            } else {
                if (isdigit(p[i])) {
                    str[k].push_back(p.substr(start, i - start));
                    start = i;
                }
            }
            digitCur = isdigit(p[i]);
        }

        str[k].push_back(p.substr(start));
    }

    sort(str.begin(), str.begin() + n, comp);

    for (int i = 0; i < n; ++i) {
        for (auto x : str[i]) cout << x;
        cout << "\n";
    }

    return 0;
}