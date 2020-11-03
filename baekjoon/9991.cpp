#include <bits/stdc++.h>

using namespace std;

const int MAX = 5e4;
const int INF = 1e9;
typedef long long ll;

struct Word {
    string s;
    int index;

    bool operator<(const Word& other) const {
        return s < other.s;
    }
};

int W, N;
vector<Word> dic;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> W >> N;
    string s;
    for (int i = 1; i <= W; ++i)
    {
        cin >> s;
        dic.push_back({s, i});
    }

    sort(dic.begin(), dic.end());

    int k;
    for (int i = 0; i < N; ++i)
    {
        cin >> k >> s;
        auto pos = lower_bound(dic.begin(), dic.end(), (Word) {s, 0});
        if (pos + k - 1 > dic.end()) {
            cout << -1 << "\n";
        } else if ((pos + k - 1)->s.compare(0, s.size(), s) == 0) {
            cout << (pos + k - 1)->index << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}
