#include <iostream>

using namespace std;

const int MAX = 1e5 + 1;

int n, m;
string rps;
string mine;

int partial[MAX];

void getPartial(string needle) {

    int size = needle.size();
    int start = 1, matched = 0;

    while (start + matched < size) {
        if (needle[start + matched] == needle[matched]) {
            ++matched;
            partial[start + matched - 1] = matched;
        } else {
            if (matched == 0) {
                ++start;
            } else {
                start += matched - partial[matched - 1];
                matched = partial[matched - 1];
            }
        }
    }
}

pair<int, int> kmp(string haystack, string needle) {

    int szh = haystack.size();
    int szn = needle.size();
    int max_matched_index = -1;
    int max_matched = 0;
    int start = 0, matched = 0;

    while (start + matched < szh) {
        if (matched < szn && haystack[start + matched] == needle[matched]) {
            ++matched;
            if (max_matched < matched) {
                max_matched = matched;
                max_matched_index = start;
            }
        } else {
            if (matched == 0) {
                ++start;
            } else {
                start += matched - partial[matched - 1];
                matched = partial[matched - 1];
            }
        }

    }

    return {max_matched, max_matched_index};
}

int main() {
    cin >> n;
    cin >> m;
    cin >> rps;
    cin >> mine;

    for (int i = 0; i < m; ++i) {
        switch (mine[i]) {
            case 'R':
                mine[i] = 'S';
                break;
            case 'P':
                mine[i] = 'R';
                break;
            case 'S':
                mine[i] = 'P';
                break;
        }
    }

    getPartial(mine);
    int lo = 0;
    int hi = m;
    pair<int, int> ret = {0, 1e9};
    ret = kmp(rps, mine.substr(lo, hi - lo));
    cout << index << "\n";
    return 0;
}
