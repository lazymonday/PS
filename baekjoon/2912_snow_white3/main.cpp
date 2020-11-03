#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 3e5;
vector<int> freq[MAX + 1];
int colors[MAX + 1];
int n, c;

inline int getFreq(int l, int r, int c) {
    return upper_bound(freq[c].begin(), freq[c].end(), r) - lower_bound(freq[c].begin(), freq[c].end(), l);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> c;

    for (int i = 1; i <= n; ++i) {
        cin >> colors[i];
        freq[colors[i]].push_back(i);
    }

    int m, l, r;
    cin >> m;
    for (int j = 0; j < m; ++j) {
        cin >> l >> r;

        int ans = 0;
        for (int i = 0; i < 20; ++i) {
            int select = l + rand() % (r - l + 1);
            if (getFreq(l, r, colors[select]) > (r - l + 1) / 2) {
                ans = colors[select];
                break;
            }
        }

        if (ans == 0) {
            cout << "no\n";
        } else {
            cout << "yes " << ans << "\n";
        }
    }
    return 0;
}
